#include <iostream>

template<int N, int M> 
class Matrix
{
    double _vals[N][M];

    public:
    double&     operator() (int i, int j) { return _vals[i][j]; }

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
