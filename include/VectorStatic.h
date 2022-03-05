

template<int N> 
class Vector
{
    public:
    double  _val[N];

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
template<>
class Vector<3>
{

};