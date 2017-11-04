#ifndef __PULSRWINDOW_MANAGER__H__
#define __PULSRWINDOW_MANAGER__H__

#include <Grawlog/Logger.hpp>
#include <map>
#include <memory>
#include <Pulsr.Core/Window/Manager.hpp>
#include <string>
#include "./Window.hpp"
#include <Windows.h>

namespace Pulsr::Window
{
	class ManagerImpl : public Core::Window::Manager
	{
	private:
		typedef std::map<HWND, std::shared_ptr<WindowImpl>> WindowList;

	public:
		ManagerImpl();
		~ManagerImpl();
		void Dispose();
		void Create( const std::string& name );
		bool HasWork();
		void Update();
		static LRESULT CALLBACK WndProcStatic(HWND handle, UINT message, WPARAM param1, LPARAM param2);
		LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM param1, LPARAM param2);

	private:
		HINSTANCE _hInstance;
		WindowList _windows;
	};
}

#endif
