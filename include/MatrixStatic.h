
template<int N, int M> 
class Matrix
{
    double _vals[N][M];

    double&     operator(int i, int j) { return _vals[i][j]; }
};
