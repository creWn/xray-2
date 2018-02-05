////////////////////////////////////////////////////////////////////////////
//	Created 	: 18.12.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_MEMORY_SEQUENTIAL_CHUNK_READER_INLINE_H_INCLUDED
#define XRAY_MEMORY_SEQUENTIAL_CHUNK_READER_INLINE_H_INCLUDED

#define TEMPLATE_SIGNATURE			template < typename implementation >
#define SEQUENTIAL_CHUNK_READER		xray::memory::sequential_chunk_reader< implementation >

TEMPLATE_SIGNATURE
inline void SEQUENTIAL_CHUNK_READER::construct		( )
{
	impl( ).m_last_position	= 0;
}

TEMPLATE_SIGNATURE
inline unsigned SEQUENTIAL_CHUNK_READER::chunk_position	( unsigned const chunk_id )
{
	reader&	reader			= impl( ).reader( );
	if ( impl( ).m_last_position && (impl( ).m_last_position < reader.length( ) ) ) {
		reader.seek			( impl( ).m_last_position );
		unsigned const id		= reader.r_unsigned();
		if ( id == chunk_id )
			return			( impl( ).m_last_position );
	}
	
	reader.rewind			( );
	while ( !reader.eof( ) ) {
		unsigned const result	= reader.tell( );
		unsigned const id		= reader.r_unsigned( );
		unsigned const size		= reader.r_unsigned( ) & 0x3fffffff;
		if ( id != chunk_id ) {
			reader.advance	( size );
			continue;
		}

		impl( ).m_last_position	= reader.tell( ) + size;
		return				( result );
	}

	return					( unsigned( -1 ) );
}

TEMPLATE_SIGNATURE
inline implementation& SEQUENTIAL_CHUNK_READER::impl( )
{
	return					( (implementation&)*this );
}

#undef SEQUENTIAL_CHUNK_READER
#undef TEMPLATE_SIGNATURE

#endif // #ifndef XRAY_MEMORY_SEQUENTIAL_CHUNK_READER_INLINE_H_INCLUDED