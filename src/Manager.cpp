#include "./Manager.hpp"

namespace Pulsr::Window
{
	ManagerImpl::ManagerImpl()
		: Core::Window::Manager()
		, _hInstance(GetModuleHandle(NULL))
		, _windows(WindowList())
	{
		DLOG(DIAG);
	}

	ManagerImpl::~ManagerImpl()
	{
		DLOG(DIAG);
		Dispose();
	}

	void ManagerImpl::Dispose()
	{
		DLOG(DIAG);
		_windows.clear();
	}
	
	void ManagerImpl::Create( const std::string& name )
	{
		DLOG(DIAG);

		// 1. First, register a windows class for the window
		WNDCLASSEX windowClass;
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = 0;
		windowClass.lpfnWndProc = ManagerImpl::WndProcStatic; // todo
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = sizeof(ManagerImpl*);
		windowClass.hInstance = _hInstance;
		windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.hbrBackground = ((HBRUSH)(COLOR_WINDOW + 1));
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = name.c_str();
		windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		if(!RegisterClassEx(&windowClass))
		{
			MessageBox(NULL, "Window Registration Failed!", "Error!"
				, MB_ICONEXCLAMATION | MB_OK);
		}

		// 2. Next, create the window itself
		auto handle = CreateWindowEx(WS_EX_CLIENTEDGE
			, name.c_str()
			, name.c_str()
			, WS_OVERLAPPEDWINDOW
			, CW_USEDEFAULT
			, CW_USEDEFAULT
			, 1280
			, 720
			, NULL
			, NULL
			, _hInstance
			, static_cast<LPVOID>(this));
	
		if(handle == NULL)
		{
			MessageBox(NULL, "Window Creation Failed!", "Error!"
				, MB_ICONEXCLAMATION | MB_OK);
		}

		// 3. Lastly, create a window and pass it the handle
		auto window = std::make_shared<WindowImpl>(name, handle);
		window->OnOpen += std::bind(&ManagerImpl::OnWindowOpen, this, std::placeholders::_1);
		window->OnClose += std::bind(&ManagerImpl::OnWindowClose, this, std::placeholders::_1);
		_windows[handle] = window;
		window->Open();
	}

	bool ManagerImpl::HasWork()
	{
		DLOG(DIAG);
		return !_windows.empty();
	}

	void ManagerImpl::Update()
	{
		DLOG(DIAG);
		MSG message;
		ZeroMemory(&message, sizeof(MSG));
		if (PeekMessage(&message, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
		
	LRESULT CALLBACK ManagerImpl::WndProcStatic(HWND handle, UINT message, WPARAM param1, LPARAM param2)
	{
		// DLOG(DIAG);
		if (message == WM_NCCREATE)
		{
			auto pcs = reinterpret_cast<CREATESTRUCT*>(param2);
			LPVOID self = pcs->lpCreateParams;
			SetWindowLongPtr(handle, 0, reinterpret_cast<LONG_PTR>(self));
		}

		auto manager = reinterpret_cast<ManagerImpl*>(GetWindowLongPtr(handle, 0));
		return manager->WndProc(handle, message, param1, param2);
	}

	LRESULT CALLBACK ManagerImpl::WndProc(HWND handle, UINT message, WPARAM param1, LPARAM param2)
	{
		// DLOG(DIAG);
		switch(message)
		{
			case WM_DESTROY:
				PostQuitMessage(0);
				_windows[handle]->Close();
				_windows.erase(handle);
				break;

			default:
				return DefWindowProc(handle, message, param1, param2);
		}

		return 0;
	}
}
