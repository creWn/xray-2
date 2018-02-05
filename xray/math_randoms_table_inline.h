#ifndef RANDOMS_RANGE_INLINE_H_INCLUDED
#define RANDOMS_RANGE_INLINE_H_INCLUDED

namespace xray {
namespace math {

template <unsigned num_randoms, unsigned range, allow_duplicates_bool allow_duplicates>
randoms_table<num_randoms, range, allow_duplicates>::randoms_table (unsigned seed)
{
	random32				random(seed);

#ifndef MASTER_GOLD
	if ( !identity(allow_duplicates) )
		R_ASSERT			(num_randoms <= 32768, "maximum table length without duplicates is 32768");
#endif // #ifndef MASTER_GOLD
	
	for ( unsigned i=0; i<num_randoms; ++i )
	{
		unsigned number		=	0;
		while ( xray::identity(true) ) 	
		{
			number		=	random.random(range);
			if ( identity(allow_duplicates == allow_duplicates_true) || 
				 std::find(m_randoms.begin(), m_randoms.end(), number) == m_randoms.end() )
			{
				break;
			}
		}

		m_randoms.push_back		(number);
	}

	m_index				=	0;
}

template <unsigned num_randoms, unsigned range, allow_duplicates_bool allow_duplicates>
unsigned   randoms_table<num_randoms, range, allow_duplicates>::next_random ()
{
	unsigned	result			=	m_randoms[m_index];
	++m_index;
	if ( m_index == num_randoms )
	{
		m_index			=	0;
	}

	return					result;
}

template <unsigned num_randoms, unsigned range, allow_duplicates_bool allow_duplicates>
void   randoms_table<num_randoms, range, allow_duplicates>::to_first_random	()
{
	m_index				=	0;
}

} // namespace math
} // namespace xray

#endif // #define RANDOMS_RANGE_INLINE_H_INCLUDED