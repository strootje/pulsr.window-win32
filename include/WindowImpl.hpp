#ifndef __PULSR_DRAWING_WINDOWIMPL__H__
#define __PULSR_DRAWING_WINDOWIMPL__H__

#include <Pulsr.Core/Drawing/Window.hpp>
#include <Windows.h>

namespace Pulsr { namespace Drawing
{
	class WindowImpl : public Core::Drawing::Window
	{
	private:
		HWND _handle;

	public:
		WindowImpl();
		~WindowImpl();
		void SetHandle( const HWND& handle );
		void Show();
		void Hide();
		void Close();
		LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM param1, LPARAM param2);
	};
}}

#endif




