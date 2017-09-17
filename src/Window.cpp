#include "./Window.hpp"

namespace Pulsr::Window
{
	WindowImpl::WindowImpl(  const std::string& name, HWND handle )
		: Core::Window::Window(name)
		, _handle(handle)
	{
		DLOGEVT(INFO, CONSTRUCT);
	}

	WindowImpl::~WindowImpl()
	{
		DLOGEVT(INFO, DESTRUCT);
	}

	void WindowImpl::Dispose()
	{
		DLOGEVT(INFO, DISPOSE);
	}

	void WindowImpl::Open()
	{
		ShowWindow(_handle, SW_SHOW);
		Core::Window::Window::Open();
		UpdateWindow(_handle);
	}
}
