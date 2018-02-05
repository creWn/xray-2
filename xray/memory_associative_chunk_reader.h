////////////////////////////////////////////////////////////////////////////
//	Created 	: 18.12.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_MEMORY_ASSOCIATIVE_CHUNK_READER_H_INCLUDED
#define XRAY_MEMORY_ASSOCIATIVE_CHUNK_READER_H_INCLUDED

namespace xray {
namespace memory {

template < typename implementation >
class associative_chunk_reader {
public:
	inline	void	construct		( );
	inline	unsigned		chunk_position	( unsigned chunk_id );

private:
	typedef std::pair<unsigned, unsigned>		Pair;

	struct predicate {
		unsigned	m_chunk_id;

		inline		predicate		( unsigned const chunk_id ) :
			m_chunk_id	( chunk_id )
		{
		}

		inline bool	operator( )		( Pair const& value ) const
		{
			return	( m_chunk_id == value.first );
		}
	}; // struct predicate

private:
	inline	implementation&	impl	( );
}; // class reader

} // namespace memory
} // namespace xray

#include <xray/memory_associative_chunk_reader_inline.h>

#endif // #ifndef XRAY_MEMORY_ASSOCIATIVE_CHUNK_READER_H_INCLUDED