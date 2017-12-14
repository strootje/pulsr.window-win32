#include "./WindowImpl.hpp"
#include <Grawlog/Logger.hpp>
#include <Guardog/Guard.hpp>

namespace Pulsr { namespace Drawing
{
	WindowImpl::WindowImpl()
	{
		LOG(DIAG);
	}

	WindowImpl::~WindowImpl()
	{
		LOG(DIAG);
	}

	void WindowImpl::SetHandle( const HWND& handle )
	{
		LOG(DIAG);
		if (_handle == nullptr)
		{
			_handle = handle;
		}
	}

	void WindowImpl::Show()
	{
		LOG(DIAG);
		// THROWIFNULL(_handle);

		ShowWindow(_handle, SW_SHOW);
		UpdateWindow(_handle);
	}

	void WindowImpl::Hide()
	{
		LOG(DIAG);
		// THROWIFNULL(_handle);

		ShowWindow(_handle, SW_HIDE);
	}

	void WindowImpl::Close()
	{
		LOG(DIAG);
		// THROWIFNULL(_handle);

		LOG(INFO) << "TODO: destroy window";
	}

	LRESULT CALLBACK WindowImpl::WndProc(HWND handle, UINT message, WPARAM param1, LPARAM param2)
	{
		// DLOG(DIAG);
		switch(message)
		{
			case WM_DESTROY:
				PostQuitMessage(0);
				break;

			default:
				return DefWindowProc(handle, message, param1, param2);
		}

		return 0;
	}
}}
