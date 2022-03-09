#include <iostream>

template <int N, int M>
class Matrix
{
    double _vals[N][M];

public:
    double &operator()(int i, int j) { return _vals[i][j]; }

    Vector<N> operator*(Vector<N> &b)
    {
        int i, j;
        Vector<N> ret;

        for (i = 0; i < N; i++)
        {
            ret[i] = 0;
            for (j = 0; j < N; j++)
                ret[i] += _vals[i][j] * b[j];
        }

        return ret;
    }
    
    void Print()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                std::cout << std::setw(10) << std::setprecision(3) << _vals[i][j] << ", ";
            }
            std::cout << std::endl;
        }
    }
};
