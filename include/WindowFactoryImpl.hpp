#ifndef __PULSR_WINDOWING_WINDOWFACTORYIMPL__H__
#define __PULSR_WINDOWING_WINDOWFACTORYIMPL__H__

#include <Pulsr.Core/Window/Factory.hpp>
#include <Pulsr.Core/Window/Window.hpp>
#include <memory>

namespace Pulsr { namespace Windowing
{
	/**
	 * Window Factory able to create a window cross platform (windows implementation)
	 */
	class WindowFactoryImpl : public Core::Window::Factory
	{
	public:
		/**
		 * Method to create a new window
		 * \returns  The created window
		 */
		std::shared_ptr<Core::Window::Window> Create();
	};
}}

#endif
