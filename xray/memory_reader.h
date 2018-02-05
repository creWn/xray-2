////////////////////////////////////////////////////////////////////////////
//	Created 	: 19.12.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_MEMORY_READER_H_INCLUDED
#define XRAY_MEMORY_READER_H_INCLUDED

#include <xray/memory_reader_wrapper.h>

namespace xray {
namespace memory {

class XRAY_CORE_API reader : public reader_wrapper< reader > {
public:
	inline			reader		( non_null< u8 const, u8 const* >::ptr data, unsigned size, unsigned position = 0 );
	inline	void	r			( pvoid destination, unsigned destination_size, unsigned size );
			pcstr	r_string	( );
			void	skip_string	( );
	inline	void	advance		( unsigned offset );
	inline	void	seek		( unsigned new_position );
	inline	void	rewind		( );

public:
	inline	bool	eof			( ) const;
	inline	unsigned		elapsed		( ) const;
	inline	unsigned		tell		( ) const;
	inline	unsigned		length		( ) const;
	inline	pcbyte	pointer		( ) const;
	inline	pcbyte	data		( ) const;

private:
	pcbyte	m_data;
	pcbyte	m_pointer;
	unsigned		m_size;
}; // class reader

} // namespace memory
} // namespace xray


namespace xray {
namespace memory {

template class XRAY_CORE_API reader_wrapper< reader >;

} // namespace memory
} // namespace xray

#include <xray/memory_reader_inline.h>

#endif // #ifndef XRAY_MEMORY_READER_H_INCLUDED