#ifndef XRAY_RANDOMS_GENERATOR_H_INCLUDED
#define XRAY_RANDOMS_GENERATOR_H_INCLUDED

namespace xray {
namespace math {

class random32
{
public:
			random32	(unsigned start_seed = 0) : m_seed(start_seed) {}

	unsigned		seed		()			{ return	m_seed; }
	void	seed		(unsigned seed)	{ m_seed	= seed; }
	unsigned		random		(unsigned range)	
	{
		m_seed	= 0x08088405*m_seed + 1;
		return	(unsigned(u64(m_seed)*u64(range) >> 32));
	}

private:
	unsigned					m_seed;
};
	 
} // namespace math
} // namespace xray

#endif // #ifndef XRAY_RANDOMS_GENERATOR_H_INCLUDED