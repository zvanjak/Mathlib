#if !defined  __MML_BASE_H
#define __MML_BASE_H

#include <cmath>

namespace MML
{
	class	MathLibException
	{
	public:
		MathLibException();
		MathLibException( int nType );
		~MathLibException();

		int		m_nType;
	};
}

#endif