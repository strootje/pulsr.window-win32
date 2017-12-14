#include "./ContainerBuilder.hpp"
#include <Grawlog/Logger.hpp>

#include "./WindowFactoryImpl.hpp"
#include <Pulsr.Core/Drawing/WindowFactory.hpp>

namespace Pulsr { namespace Drawing
{
	ContainerBuilder::ContainerBuilder()
	{
		DLOG(DIAG);
		registerType<WindowFactoryImpl>().as<Core::Drawing::WindowFactory>();
	}

	ContainerBuilder::~ContainerBuilder()
	{
		DLOG(DIAG);
	}
}}
