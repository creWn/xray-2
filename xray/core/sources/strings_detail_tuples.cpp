////////////////////////////////////////////////////////////////////////////
//	Created 	: 10.10.2008
//	Author		: Sergey Chechin
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"

using xray::strings::detail::tuples;



static void process										( unsigned const index, unsigned const count, pcstr *strings )
{
	XRAY_UNREFERENCED_PARAMETER		( index );
	unsigned const max_string_size		= 1024;
	pstr const temp					= (pstr)ALLOCA((count*(max_string_size + 4) + 1)*sizeof(**strings));
	pstr k							= temp;
	*k++							= '[';
	for ( unsigned i = 0; i < count; ++i ) {
		for ( pcstr j = strings[i], e = j + max_string_size; *j && j < e; ++k, ++j )
			*k	= *j;

		*k++						= ']';
		
		if ( i + 1 >= count )
			continue;

		*k++						= '[';
		*k++						= '\r';
		*k++						= '\n';
	}

	*k								= 0;

	FATAL							( "buffer overflow: cannot concatenate strings(%d):\r\n%s", index, temp	);
}

void tuples::error_process								( ) const
{
	pcstr							strings[6];

	unsigned part_size					= 0;
	unsigned overrun_string_index		= unsigned(-1);
	for ( unsigned i=0; i < m_count; ++i ) {
		strings[i]					= m_strings[i].first;

		if ( overrun_string_index != (unsigned)-1 )
			continue;

		part_size					+= m_strings[i].second;
		if ( part_size > max_concat_result_size )
			overrun_string_index	= i;
	}
	
	ASSERT							( overrun_string_index != unsigned(-1) );

	process							( overrun_string_index, m_count, strings );
}