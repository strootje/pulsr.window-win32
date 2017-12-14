#ifndef __PULSR_DRAWING_CONTAINERBUILDER__H__
#define __PULSR_DRAWING_CONTAINERBUILDER__H__

#include <Hypodermic/Hypodermic.h>

namespace Pulsr { namespace Drawing
{
	/**
	 * ContainerBuilder for the Drawing Module
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
