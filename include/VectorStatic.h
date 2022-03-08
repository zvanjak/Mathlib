#if !defined  __MML_VECTOR_STATIC_H
#define __MML_VECTOR_STATIC_H

#include <initializer_list>

template<int N> 
class Vector
{
    public:
    double  _val[N];

    Vector() {}

    Vector(std::initializer_list<double> list) 
    { 
       	int count{ 0 };
		for (auto element : list)
		{
			_val[count] = element;
			++count;

            if( count >= N )
                break;
		}
    }

    double& operator[](int n) { return _val[n]; }
    //double  operator[](int n) const { return _val[n]; }

    Vector operator+(Vector &b )
    {
        Vector ret;
        for(int i=0; i<N; i++)
            ret._val[i] = _val[i] + b._val[i];
        return ret;
    }

    Vector operator-(Vector &b )
    {
        Vector ret;
        for(int i=0; i<N; i++)
            ret._val[i] = _val[i] - b._val[i];
        return ret;
    }

};

// SPECIJALIZACIJE ZA 2, 3 I 4
// template<>
// class Vector<3>
// {

// };

#endif