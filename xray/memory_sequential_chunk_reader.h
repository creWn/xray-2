////////////////////////////////////////////////////////////////////////////
//	Created 	: 18.12.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_MEMORY_SEQUENTIAL_CHUNK_READER_H_INCLUDED
#define XRAY_MEMORY_SEQUENTIAL_CHUNK_READER_H_INCLUDED

namespace xray {
namespace memory {

template < typename implementation >
class sequential_chunk_reader {
public:
	inline	void	construct		( );
	inline	unsigned		chunk_position	( unsigned chunk_id );

private:
	inline	implementation&	impl	( );
}; // class reader

} // namespace memory
} // namespace xray

#include <xray/memory_sequential_chunk_reader_inline.h>

#endif // #ifndef XRAY_MEMORY_SEQUENTIAL_CHUNK_READER_H_INCLUDED