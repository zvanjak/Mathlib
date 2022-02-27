#if !defined  __MINIMAL_MATH_LIB_H
#define __MINIMAL_MATH_LIB_H

#include <cmath>


class	MathLibException
{
public:
	MathLibException();
	MathLibException( int nType );
	~MathLibException();

	int		m_nType;
};

#endif