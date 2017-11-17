#include "./ContainerBuilder.hpp"
#include <Grawlog/Logger.hpp>

#include "./WindowFactoryImpl.hpp"
#include <Pulsr.Core/Window/Factory.hpp>

namespace Pulsr { namespace Windowing
{
	ContainerBuilder::ContainerBuilder()
	{
		DLOG(DIAG);
		registerType<WindowFactoryImpl>().as<Core::Window::Factory>();
	}

	ContainerBuilder::~ContainerBuilder()
	{
		DLOG(DIAG);
	}
}}
