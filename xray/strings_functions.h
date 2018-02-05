////////////////////////////////////////////////////////////////////////////
//	Created 	: 10.10.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string.h>					// for strcmp
#include <xray\core\sources\memory.h>
#include "strings_functions.h"
#include "debug_macros.h"

namespace xray {
namespace strings {

inline unsigned length					( pcstr string );
inline int	compare					( pcstr left, pcstr right );
inline int	compare_insensitive		( pcstr left, pcstr right );
inline bool equal					( pcstr left, pcstr right ) { return !compare(left, right); }
bool		compare_with_wildcards	( pcstr wild, pcstr string );

template <class number_type>
bool		convert_string_to_number	( pcstr const string, number_type * const out_result )
{
	float	temp_result;
	if ( !convert_string_to_number(string, & temp_result) )
		return						false;
	* out_result				=	(number_type)temp_result;
	return							true;
}

bool		convert_string_to_number	( pcstr const string, float * const out_result );

inline pstr copy					( pstr destination, unsigned destination_size, pcstr source );
template <int count>
inline pstr copy					( char (&destination)[count], pcstr source );

inline pstr copy_n					( pstr const destination, size_t const destination_size, pcstr const source, size_t const count );

template < typename allocator_type >
inline pstr duplicate				( allocator_type& allocator, pcstr const string );

template <typename predicate_type>
inline bool	iterate_items			( pcstr string, unsigned length, predicate_type const& predicate, char const separator = ',');

template <typename predicate_type>
inline bool	iterate_items			( pcstr string, predicate_type const& predicate, char const separator = ',' );

inline pcstr get_token				( pcstr string, pstr result, unsigned result_size, char const separator )
{
	pcstr found				= strchr((char*)string, separator);
	if ( !found ) {
		strings::copy		( result, result_size, string );
		return				0;
	}

	R_ASSERT				( unsigned(found - string) < result_size );
	memory::copy		( result, result_size-1, string, unsigned(found - string) );
	result[found - string]	= 0;
	
	++found;
	return					found;
}

template <int count>
inline pcstr get_token				( pcstr string, char (&result)[count], char const separator )
{
	return				( get_token( string, result, count*sizeof(char), separator ) );
}

inline pcstr get_token_reverse		( pcstr string, pstr result, unsigned result_size, char const separator )
{
	pcstr found				= strrchr((char*)string, separator);
	if ( !found ) {
		strings::copy		( result, result_size, string );
		return				0;
	}

	R_ASSERT_U				( unsigned(found - string) < result_size);
	unsigned const res_str_size	= unsigned(strlen(string)-(found - string)-1);
	xray::memory::copy		( result, result_size-1, found+1, res_str_size );
	result[res_str_size]	= 0;

	return					found;
}

template <int count>
inline pcstr get_token_reverse		( pcstr string, char (&result)[count], char const separator )
{
	return				( get_token_reverse( string, result, count*sizeof(char), separator ) );
}

inline bool starts_with				( pcstr const source, pcstr const string_to_search_for )
{
	pcstr i=source, j=string_to_search_for;
	for ( ; *i && *j; ++i, ++j )
		if ( *i != *j )
			return		false;

	return				!*j;
}

inline bool ends_with				( pcstr const source, unsigned const source_length, pcstr const string_to_search_for, unsigned const string_to_search_for_length )
{
	pcstr i=source + source_length - 1, j=string_to_search_for + string_to_search_for_length - 1;
	for ( ; (i >= source) && (j >= string_to_search_for); --i, --j )
		if ( *i != *j )
			return		false;

	return				j < string_to_search_for;
}

} // namespace strings
} // namespace xray

#include <xray/strings_functions_inline.h>