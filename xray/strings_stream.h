////////////////////////////////////////////////////////////////////////////
//	Created		: 08.04.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_STRINGS_STREAM_H_INCLUDED
#define XRAY_STRINGS_STREAM_H_INCLUDED

namespace xray {
namespace strings {

class XRAY_CORE_API stream {
public:
		explicit		stream			( memory::base_allocator* allocator );
						~stream			( );
		void __cdecl	append			( pcstr format, ... );
		pcbyte			get_buffer		( ) const;
		unsigned				get_buffer_size	( ) const;
		void			clear			( );

private:
	memory::base_allocator*					m_allocator;
	pbyte									m_buffer;
	unsigned										m_buffer_size;
	unsigned										m_allocated_size;
}; // class strings_stream

} // namespace strings
} // namespace xray

#include <xray/strings_stream_inline.h>

#endif // #ifndef XRAY_STRINGS_STREAM_H_INCLUDED