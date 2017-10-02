#include "./Window.hpp"

namespace Pulsr::Window
{
	WindowImpl::WindowImpl(  const std::string& name, HWND handle )
		: Core::Window::Window(name)
		, _handle(handle)
	{
		DLOG(DIAG);
	}

	WindowImpl::~WindowImpl()
	{
		DLOG(DIAG);
	}

	void WindowImpl::Dispose()
	{
		DLOG(DIAG);
	}

	void WindowImpl::Open()
	{
		DLOG(DIAG);
		ShowWindow(_handle, SW_SHOW);
		Core::Window::Window::Open();
		UpdateWindow(_handle);
	}
}
