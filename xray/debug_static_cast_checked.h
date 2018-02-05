////////////////////////////////////////////////////////////////////////////
//	Created 	: 15.12.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef DEBUG

namespace xray {
namespace debug {
namespace detail {
namespace static_cast_checked {

template < typename destination_type >
struct value {
	template < typename source_type >
	inline static void check		( source_type* const source )
	{
		ASSERT		( dynamic_cast< destination_type >( source ) == static_cast< destination_type >( source ) );
	}

	template <typename source_type>
	inline static void check		(source_type &source)
	{
		ASSERT		( &dynamic_cast< destination_type >( source ) == &static_cast< destination_type >( source ) );
	}
};

template < typename source_type, typename destination_type, bool is_polymrphic >
struct helper {
	inline static void check		( source_type source )
	{
		value<
			destination_type
		>::check	( source );
	}
}; // struct helper

template < typename source_type, typename destination_type >
struct helper<source_type, destination_type, false> {
	inline static void check		( source_type )
	{
	}
}; // struct helper

} // namespace static_cast_checked
} // namespace detail
} // namespace debug

template < typename destination_type, typename source_type >
inline destination_type static_cast_checked	( source_type const& source )
{
	typedef typename std::remove_pointer<source_type>::type			pointerless_type;
	typedef typename std::remove_reference<pointerless_type>::type	pure_source_type;

	debug::detail::static_cast_checked::helper<source_type const &, destination_type, std::is_polymorphic<pure_source_type>::value>::check( source );

	return ( static_cast< destination_type >( source ) );
}

template < typename destination_type, typename source_type >
inline destination_type static_cast_checked	( source_type& source )
{
	typedef typename std::remove_pointer<source_type>::type			pointerless_type;	typedef typename std::remove_reference<pointerless_type>::type	pure_source_type;	debug::detail::static_cast_checked::helper<
		source_type&,
		destination_type,
		std::is_polymorphic<pure_source_type>::value>::check( source );

	return ( static_cast< destination_type >( source ) );
}

} // namespace xray

#else // #ifdef DEBUG

namespace xray {

template < typename destination_type, typename source_type >
inline destination_type static_cast_checked	( source_type const & source )
{
		return			( static_cast< destination_type >( source ) );
}

template < typename destination_type, typename source_type >
inline destination_type static_cast_checked	( source_type & source )
{
	return			( static_cast< destination_type >( source ) );
}

} // namespace xray

#endif // #ifdef DEBUG