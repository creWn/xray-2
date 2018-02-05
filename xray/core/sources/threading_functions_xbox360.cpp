////////////////////////////////////////////////////////////////////////////
//	Created		: 06.05.2010
//	Author		: Sergey Chechin
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <xray/os_preinclude.h>
#include <xray/os_include.h>

namespace xray {
namespace threading {

void set_current_thread_affinity_impl	(unsigned const hardware_thread)
{
	XSetThreadProcessor				(GetCurrentThread(), hardware_thread);
}

unsigned actual_core_count ( )
{
	return							6;
}

} // namespace threading
} // namespace xray