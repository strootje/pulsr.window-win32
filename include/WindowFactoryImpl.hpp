#ifndef __PULSR_DRAWING_WINDOWFACTORYIMPL__H__
#define __PULSR_DRAWING_WINDOWFACTORYIMPL__H__

#include <Pulsr.Core/Drawing/WindowFactory.hpp>
#include <Pulsr.Core/Drawing/Window.hpp>
#include <Windows.h>
#include <memory>

namespace Pulsr { namespace Drawing
{
	/**
	 * Window Factory able to create a window cross platform (windows implementation)
	 */
	class WindowFactoryImpl : public Core::Drawing::WindowFactory
	{
	private:
		HINSTANCE _hInstance;

	public:
		/**
		 * Constructor
		 */
		WindowFactoryImpl();

		/**
		 * Destructor
		 */
		~WindowFactoryImpl();

		/**
		 * Method to create a new window
		 * \returns  The created window
		 */
		std::shared_ptr<Core::Drawing::Window> Create() const;

		/**
		 */
		void Dispatch() const;

		/**
		 */
		static LRESULT CALLBACK WndProcStatic(HWND handle, UINT message, WPARAM param1, LPARAM param2);

	private:
		/**
		 */
		void RegisterWindowClasses() const;
	};
}}

#endif
