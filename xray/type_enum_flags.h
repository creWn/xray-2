////////////////////////////////////////////////////////////////////////////
//	Created		: 06.05.2010
//	Author		: Sergey Chechin
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_TYPE_ENUM_FLAGS_H_INCLUDED
#define XRAY_TYPE_ENUM_FLAGS_H_INCLUDED

namespace xray {

template <class enum_type>
class XRAY_CORE_API enum_flags
{
public:
	enum_flags (unsigned flags = 0) : m_flags(flags) {}

	enum_flags	operator |=	(unsigned flags) 				{ m_flags |= flags; return *this; }
	enum_flags	operator &=	(unsigned flags) 				{ m_flags &= flags; return *this; }

	enum_flags	operator |  (unsigned flags) 		const 	{ return enum_flags(m_flags | flags); }
	enum_flags	operator |  (enum_type flags) 	const 	{ return enum_flags(m_flags | flags); }
	enum_flags	operator &  (unsigned flags) 		const 	{ return enum_flags(m_flags & flags); }
	enum_flags	operator &  (enum_type flags) 	const 	{ return enum_flags(m_flags & flags); }
	enum_flags	operator ~	()					const 	{ return enum_flags(~m_flags); }

	operator	bool		()					const	{ return !!m_flags; }
	operator	unsigned			()					const 	{ return m_flags; }
	operator	enum_type	()					const 	{ return (enum_type)m_flags; }

private:
	unsigned			m_flags;
};

} // namespace xray

#endif // /#ifndef XRAY_TYPE_ENUM_FLAGS_H_INCLUDED