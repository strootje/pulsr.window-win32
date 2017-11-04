#ifndef __PULSRWINDOW_WINDOW__H__
#define __PULSRWINDOW_WINDOW__H__

#include <Grawlog/Logger.hpp>
#include <Pulsr.Core/Window/Window.hpp>
#include <string>
#include <Windows.h>

namespace Pulsr::Window
{
	class WindowImpl : public Core::Window::Window
	{
	public:
		WindowImpl( const std::string& name, HWND handle );
		~WindowImpl();
		void Dispose();
		void Open();

	private:
		HWND _handle;
	};
}

#endif
