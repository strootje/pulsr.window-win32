#include "./WindowFactoryImpl.hpp"
#include "./WindowImpl.hpp"
#include <Grawlog/Logger.hpp>
#include <Guardog/Guard.hpp>

namespace Pulsr { namespace Drawing
{
	WindowFactoryImpl::WindowFactoryImpl()
		: _hInstance(GetModuleHandle(NULL))
	{
		DLOG(DIAG);
		// THROWIFNULL(_hInstance);
		RegisterWindowClasses();
	}

	WindowFactoryImpl::~WindowFactoryImpl()
	{
		DLOG(DIAG);
	}

	std::shared_ptr<Core::Drawing::Window> WindowFactoryImpl::Create() const
	{
		DLOG(DIAG);
		// 1. Create a reference window
		auto window = std::make_shared<WindowImpl>();

		// 2. Create the windows window
		auto handle = CreateWindowEx(WS_EX_CLIENTEDGE
			, "Pulsr.SimpleWindow"
			, "AN SIMPLE WINDOW"//name.c_str()
			, WS_OVERLAPPEDWINDOW
			, CW_USEDEFAULT
			, CW_USEDEFAULT
			, 1280
			, 720
			, NULL
			, NULL
			, _hInstance
			, static_cast<LPVOID>(window.get()));
	
		if(handle == NULL)
		{
			MessageBox(NULL, "Window Creation Failed!", "Error!"
				, MB_ICONEXCLAMATION | MB_OK);
		}

		// 3. Lastly, pass it the handle
		window->SetHandle(handle);
		return window;
	}
	
	void WindowFactoryImpl::Dispatch() const
	{
		// DLOG(DIAG);
		MSG message;
		ZeroMemory(&message, sizeof(MSG));
		if (PeekMessage(&message, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	LRESULT CALLBACK WindowFactoryImpl::WndProcStatic(HWND handle, UINT message, WPARAM param1, LPARAM param2)
	{
		// DLOG(DIAG);
		if (message == WM_NCCREATE)
		{
			auto pcs = reinterpret_cast<CREATESTRUCT*>(param2);
			LPVOID self = pcs->lpCreateParams;
			SetWindowLongPtr(handle, 0, reinterpret_cast<LONG_PTR>(self));
		}

		auto window = reinterpret_cast<WindowImpl*>(GetWindowLongPtr(handle, 0));
		return window->WndProc(handle, message, param1, param2);
	}

	void WindowFactoryImpl::RegisterWindowClasses() const
	{
		DLOG(DIAG);
		// Pulsr.SimpleWindow
		WNDCLASSEX windowClass;
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = 0;
		windowClass.lpfnWndProc = WindowFactoryImpl::WndProcStatic;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = sizeof(WindowImpl*);
		windowClass.hInstance = _hInstance;
		windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.hbrBackground = ((HBRUSH)(COLOR_WINDOW + 1));
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = "Pulsr.SimpleWindow";
		windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		if(!RegisterClassEx(&windowClass))
		{
			// TODO: refactor to exception with bool check in constructor
			MessageBox(NULL, "Window Registration Failed!", "Error!"
				, MB_ICONEXCLAMATION | MB_OK);
		}
	}
}}
