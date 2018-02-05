////////////////////////////////////////////////////////////////////////////
//	Created 	: 10.10.2008
//	Author		: Sergey Chechin
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_STRINGS_DETAIL_TUPLES_H_INLUDED
#define XRAY_STRINGS_DETAIL_TUPLES_H_INLUDED

namespace xray {

void XRAY_CORE_API check_stack_overflow ( unsigned query_value );

namespace strings {
namespace detail {

class XRAY_CORE_API tuples {
public:
	template < typename T0 >
	inline			tuples					( T0 p0 );

	template < typename T0, typename T1 >
	inline			tuples					( T0 p0, T1 p1 );

	template < typename T0, typename T1, typename T2 >
	inline			tuples					( T0 p0, T1 p1, T2 p2 );

	template < typename T0, typename T1, typename T2, typename T3 >
	inline			tuples					( T0 p0, T1 p1, T2 p2, T3 p3 );

	template < typename T0, typename T1, typename T2, typename T3, typename T4 >
	inline			tuples					( T0 p0, T1 p1, T2 p2, T3 p3, T4 p4 );

	template < typename T0, typename T1, typename T2, typename T3, typename T4, typename T5 >
	inline			tuples					( T0 p0, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 );

public:
			void	error_process			( ) const;
	inline	unsigned		size					( ) const;
	inline	void	concat					( pcstr result ) const;

private:
	enum {
		max_concat_result_size				= unsigned( 512*1024 ),
		max_item_count						= 6,
	};

private:
	template < unsigned index >
	struct helper {
		template < typename T >
		static inline	void	add_string	( tuples& self, T p );
		static inline	unsigned		length		( pcstr string );
		static inline	pcstr	string		( pcstr string );
	}; // struct helper

private:
	struct XRAY_CORE_API pair {
		pcstr		first;
		unsigned			second;

		inline	pair	( ) :
			first	( 0 ),
			second	( 0 )
		{
		}
		
		inline	pair	( pcstr const first, unsigned const second ) :
			first	( first ),
			second	( second )
		{
		}
	}; // struct pair;

private:
	pair			m_strings[ max_item_count ];
	unsigned 			m_count;
};

} // namespace detail
} // namespace strings
} // namespace xray

#include <xray/strings_detail_tuples_inline.h>

#endif // #ifndef XRAY_STRINGS_DETAIL_TUPLES_H_INLUDED