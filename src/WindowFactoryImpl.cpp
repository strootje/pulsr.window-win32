#include "./WindowFactoryImpl.hpp"
#include <Pulsr.Kernel/Window/WindowImpl.hpp>

namespace Pulsr { namespace Windowing
{
	std::shared_ptr<Core::Window::Window> WindowFactoryImpl::Create()
	{
		Kernel::Window::WindowImpl window;
		return std::shared_ptr<Core::Window::Window>(&window);
	}
}}
