////////////////////////////////////////////////////////////////////////////
//	Created 	: 20.12.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"

using xray::memory::chunk_reader;
using xray::memory::reader;

chunk_reader::chunk_reader					( pcbyte const data, unsigned const size ) :
	m_reader			( data + sizeof( unsigned ), size - sizeof( unsigned ) ),
	m_chunks			( 0 ),
	m_chunk_count		( 0 )
{
	m_type				= chunk_type( *( unsigned* )data );
	ASSERT				( m_type < chunk_type_count );
	construct			( );
}

chunk_reader::chunk_reader					( pcbyte const data, unsigned const size, chunk_type const type ) :
	m_reader			( data, size ),
	m_type				( type ),
	m_chunks			( 0 ),
	m_chunk_count		( 0 )

{
	construct			( );
}

void chunk_reader::construct				( )
{
	switch ( m_type ) {
		case chunk_type_sequential :	return	( sequential_chunk_reader< chunk_reader >::construct( ) );
		case chunk_type_array :			return	( array_chunk_reader< chunk_reader >::construct( ) );
		case chunk_type_associative :	return	( associative_chunk_reader< chunk_reader >::construct( ) );
		default	:						NODEFAULT();
	}
}

unsigned chunk_reader::chunk_position			( unsigned const chunk_id )
{
	switch ( m_type ) {
		case chunk_type_sequential :	return	( sequential_chunk_reader< chunk_reader >::chunk_position( chunk_id ) );
		case chunk_type_array :			return	( array_chunk_reader< chunk_reader >::chunk_position( chunk_id ) );
		case chunk_type_associative :	return	( associative_chunk_reader< chunk_reader >::chunk_position( chunk_id ) );
		default	:						NODEFAULT(return unsigned(-1));
	}
}

unsigned chunk_reader::chunk_size				( unsigned const chunk_id, chunk_type& type )
{
	unsigned const position	= chunk_position( chunk_id );
	ASSERT				( position != unsigned( -1 ) );
	m_reader.seek		( position );
	unsigned const id		= m_reader.r_unsigned( );
	ASSERT_U			( id == chunk_id );

	unsigned const temp		= m_reader.r_unsigned( );
	unsigned const size		= temp & 0x3fffffff;
	type				= chunk_type( temp >> 30 );
	return				( size );
}

chunk_reader chunk_reader::open_chunk_reader( unsigned const chunk_id )
{
	chunk_type			type;
	unsigned const size		= chunk_size( chunk_id, type );
	ASSERT				( type < chunk_type_count );
	return				( chunk_reader( m_reader.pointer( ), size, type ) );
}

reader chunk_reader::open_reader			( unsigned const chunk_id )
{
	chunk_type			type;
	unsigned const size		= chunk_size( chunk_id, type );
//	ASSERT				( type == chunk_type_count );
	return				( memory::reader( m_reader.pointer( ), size ) );
}

bool chunk_reader::chunk_exists				( unsigned const chunk_id )
{
	unsigned const position	= chunk_position( chunk_id );
	return				( position != unsigned( -1 ) );
}