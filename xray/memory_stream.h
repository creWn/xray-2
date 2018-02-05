////////////////////////////////////////////////////////////////////////////
//	Created		: 17.04.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_MEMORY_STREAM_H_INCLUDED
#define XRAY_MEMORY_STREAM_H_INCLUDED

namespace xray {
namespace memory {

class stream {
public:
	inline	explicit		stream			( memory::base_allocator* allocator );
	inline					~stream			( );
			void			append			( pcvoid buffer, unsigned buffer_size );
	inline	void			append			( unsigned value );
	inline	void			append			( int value );
	inline	void			append			( pcstr value );
	inline	pbyte			get_buffer		( ) const;
	inline	unsigned				get_buffer_size	( ) const;
	inline	void			clear			( );

private:
	memory::base_allocator*	m_allocator;
	pbyte					m_buffer;
	unsigned						m_buffer_size;
	unsigned						m_allocated_size;
}; // class stream

} // namespace memory
} // namespace xray

#include <xray/memory_stream_inline.h>

#endif // #ifndef XRAY_MEMORY_STREAM_H_INCLUDED