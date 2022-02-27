#include <iostream>

namespace MML
{
    class Matrix
    {
    public:
        Matrix() : _rows(0), _cols(0)
        {
            _ptrData = nullptr;
        }
        Matrix(int rows, int cols) : _rows(rows), _cols(cols)
        {
            _ptrData = new double *[_rows];
            for (int i = 0; i < _rows; ++i)
                _ptrData[i] = new double[_cols];
            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j) {
                    _ptrData[i][j] = 0;
                }
            }
            std::cout << "constructor \n";
        }
        Matrix(const Matrix& m) : _rows(m._rows), _cols(m._cols)
        {
            _ptrData = new double *[_rows];
            for (int i = 0; i < _rows; ++i)
                _ptrData[i] = new double[_cols];
            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j) {
                    _ptrData[i][j] = m._ptrData[i][j];
                }
            }
            std::cout << "copy constructor \n";
        }
        Matrix(Matrix&& m)
        {
            _ptrData = m._ptrData;

            _rows = m._rows;
            _cols = m._cols;

            m._rows = 0;
            m._cols = 0;
            m._ptrData = nullptr;

            std::cout << "move constructor \n";
        }
        ~Matrix()
        {
            for (int i = 0; i < _rows; ++i) {
                if (_ptrData != nullptr && _ptrData[i] != nullptr)
                    delete[] _ptrData[i];
            }
            if (_ptrData != nullptr)
                delete[] _ptrData;
            std::cout << "destructor \n";
        }

        Matrix& operator=(const Matrix& m)
        {
            if (this == &m) {
                return *this;
            }

            if (_rows != m._rows || _cols != m._cols) {
                for (int i = 0; i < _rows; ++i) {
                    delete[] _ptrData[i];
                }
                delete[] _ptrData;

                _rows = m._rows;
                _cols = m._cols;
                _ptrData = new double *[_rows];
                for (int i = 0; i < _rows; ++i)
                    _ptrData[i] = new double[_cols];
            }

            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j) {
                    _ptrData[i][j] = m._ptrData[i][j];
                }
            }
            std::cout << "operator = \n";
            return *this;
        }
        Matrix& operator=(Matrix&& m)
        {
            if (this == &m) {
                return *this;
            }

            std::swap(_ptrData, m._ptrData);

            std::swap(_rows, m._rows);
            std::swap(_cols, m._cols);

            std::cout << "move operator = \n";
            return *this;
        }

        Matrix  operator+(const Matrix &other)
        {
            Matrix temp(_rows, _cols);
            if (_rows != other._rows || _cols != other._cols)
            {
                for (int i = 0; i < _rows; i++)
                    for (int j = 0; j < _cols; j++)
                        temp._ptrData[i][j] = _ptrData[i][j];
                return temp;
            }
            else
            {
                for (int i = 0; i < _rows; i++)
                    for (int j = 0; j < _cols; j++)
                        temp._ptrData[i][j] += other._ptrData[i][j] + _ptrData[i][j];
            }
            std::cout << "operator + \n";
            return temp;
        }


    private:
        int _rows;
        int _cols;
        double **_ptrData;
    };
}