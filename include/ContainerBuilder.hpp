#ifndef __PULSR_WINDOWING_CONTAINERBUILDER__H__
#define __PULSR_WINDOWING_CONTAINERBUILDER__H__

#include <Hypodermic/Hypodermic.h>

namespace Pulsr { namespace Windowing
{
	/**
	 * ContainerBuilder for the Windowing Module
	 */
	class ContainerBuilder : public Hypodermic::ContainerBuilder
	{
	public:
		/**
		 * Constructor
		 */
		ContainerBuilder();

		/**
		 * Destructor
		 */
		virtual ~ContainerBuilder();
	};
}}

#endif
