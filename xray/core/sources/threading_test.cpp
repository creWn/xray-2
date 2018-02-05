////////////////////////////////////////////////////////////////////////////
//	Created		: 06.05.2010
//	Author		: Sergey Chechin
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <xray/testing.h>
#include <xray/core_test_suite.h>

DECLARE_LINKAGE_ID(threading_test)

namespace xray {

static threading::atomic32_type	s_threads_started	=	0;
static threading::atomic32_type	s_threads_exited	=	0;

unsigned const	array_count		=	128*1024;
threading::atomic32_type	s_value			=	0; 
unsigned 		s_array1			[array_count];
unsigned 		s_array2			[array_count];

void thread_main	( pvoid array_raw )
{
	while ( !s_threads_started )
		threading::yield( 0 );

	unsigned* const array = (unsigned*)(array_raw);
	unsigned* i			= array;
	unsigned* const e	= array + array_count;
	for ( ; i != e; ++i ) {
		*i			= threading::interlocked_exchange_add( s_value, 1 );
	}

	threading::interlocked_increment( s_threads_exited );
}


DEFINE_TEST(threading_test, core_test_suite)
{
	s_threads_started			= 0;
	s_threads_exited			= 0;

	threading::spawn( boost::bind(&thread_main, &s_array1[0]), "the first", "the first", 0, 1 % threading::core_count(), threading::tasks_unaware);
	threading::spawn( boost::bind(&thread_main, &s_array2[0]), "the second", "the second", 0, 2 % threading::core_count(), threading::tasks_unaware);
	threading::yield( 100 );
	threading::interlocked_exchange	(s_threads_started, 1);
	while ( s_threads_exited != 2 ) {
		threading::yield( 100 );
	}

	unsigned* i			= s_array1;
	unsigned* j			= s_array2;
	unsigned* const ie	= s_array1 + array_count;
	unsigned* const je	= s_array2 + array_count;
	for ( ; (i != ie) && (j != je); ) {
		if ( *i < *j ) {
			++i;
			continue;
		}

		if ( *j < *i ) {
			++j;
			continue;
		}

		TEST_ASSERT( 0, "HALT! InterlockedExchangeAdd behaviour is broken!" );
	}
}

} // namespace xray

