#include <iostream>

namespace MML
{
    class Matrix
    {
    public:
        Matrix() : _rows(0), _cols(0)
        {
            std::cout << "Matrix::default constructor \n";
            _ptrData = nullptr;
        }
        Matrix(int rows, int cols) : _rows(rows), _cols(cols)
        {
            _ptrData = new double *[_rows];
            for (int i = 0; i < _rows; ++i)
                _ptrData[i] = new double[_cols];
            for (int i = 0; i < _rows; ++i)
            {
                for (int j = 0; j < _cols; ++j)
                {
                    _ptrData[i][j] = 0;
                }
            }
            std::cout << "Matrix::constructor \n";
        }
        Matrix(const Matrix &m) : _rows(m._rows), _cols(m._cols)
        {
            _ptrData = new double *[_rows];
            for (int i = 0; i < _rows; ++i)
                _ptrData[i] = new double[_cols];
            for (int i = 0; i < _rows; ++i)
            {
                for (int j = 0; j < _cols; ++j)
                {
                    _ptrData[i][j] = m._ptrData[i][j];
                }
            }
            std::cout << "Matrix::copy constructor \n";
        }
        Matrix(Matrix &&m)
        {
            _ptrData = m._ptrData;

            _rows = m._rows;
            _cols = m._cols;

            m._rows = 0;
            m._cols = 0;
            m._ptrData = nullptr;

            std::cout << "Matrix::move constructor \n";
        }
        ~Matrix()
        {
            for (int i = 0; i < _rows; ++i)
            {
                if (_ptrData != nullptr && _ptrData[i] != nullptr)
                    delete[] _ptrData[i];
            }
            if (_ptrData != nullptr)
                delete[] _ptrData;
            std::cout << "Matrix::destructor \n";
        }

        Matrix &operator=(const Matrix &m)
        {
            if (this == &m)
            {
                return *this;
            }

            if (_rows != m._rows || _cols != m._cols)
            {
                for (int i = 0; i < _rows; ++i)
                {
                    delete[] _ptrData[i];
                }
                delete[] _ptrData;

                _rows = m._rows;
                _cols = m._cols;
                _ptrData = new double *[_rows];
                for (int i = 0; i < _rows; ++i)
                    _ptrData[i] = new double[_cols];
            }

            for (int i = 0; i < _rows; ++i)
            {
                for (int j = 0; j < _cols; ++j)
                {
                    _ptrData[i][j] = m._ptrData[i][j];
                }
            }
            std::cout << "Matrix::operator = \n";
            return *this;
        }
        Matrix &operator=(Matrix &&m)
        {
            if (this == &m)
            {
                return *this;
            }

            std::swap(_ptrData, m._ptrData);

            std::swap(_rows, m._rows);
            std::swap(_cols, m._cols);

            std::cout << "Matrix::move operator = \n";
            return *this;
        }

        double *operator[](int i)
        {
            return _ptrData[i];
        }

        Matrix operator+(const Matrix &other)
        {
            std::cout << "Matrix::operator + START \n";

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
            std::cout << "Matrix::operator + END \n";
            return temp;
        }

        void MakeUnitMatrix(void)
        {
            if (_rows == _cols)
            {
                for (int i = 0; i < _rows; i++)
                    for (int j = 0; j < _cols; j++)
                        if (i == j)
                            _ptrData[i][j] = 1;
                        else
                            _ptrData[i][j] = 0;
            }
        }

        void Print(void)
        {
            std::cout << "Rows: " << _rows << "  Cols: " << _cols << std::endl;

            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _cols; j++)
                {
                    std::cout << _ptrData[i][j] << ", ";
                }
                std::cout << std::endl;
            }
        }

    private:
        int _rows;
        int _cols;
        double **_ptrData;
    };
}