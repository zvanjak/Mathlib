#if !defined  __MML_MATRIX_H
#define __MML_MATRIX_H

#include "VectorN.h"

#include <iostream>
#include <iomanip>

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
                for (int j = 0; j < _cols; ++j)
                    _ptrData[i][j] = 0;
            
            //std::cout << "Matrix::constructor \n";
        }
        Matrix(int rows, int cols, std::initializer_list<double> values) : _rows(rows), _cols(cols)
        {
            _ptrData = new double *[_rows];
            for (int i = 0; i < _rows; ++i)
                _ptrData[i] = new double[_cols];
            
            int cnt = 0;
            auto val = values.begin();
            for (int i = 0; i < _rows; ++i)
                for (int j = 0; j < _cols; ++j)
                    if( val != values.end() )
                    {
                        _ptrData[i][j] = *val;
                        ++val;
                    }
                    else
                        _ptrData[i][j] = 0.0;
            
            //std::cout << "Matrix::constructor \n";
        }
        Matrix(const Matrix &m) : _rows(m._rows), _cols(m._cols)
        {
            _ptrData = new double *[_rows];
            for (int i = 0; i < _rows; ++i)
                _ptrData[i] = new double[_cols];
            for (int i = 0; i < _rows; ++i)
                for (int j = 0; j < _cols; ++j)
                    _ptrData[i][j] = m._ptrData[i][j];

            //std::cout << "Matrix::copy constructor \n";
        }
        Matrix(Matrix &&m)
        {
            _ptrData = m._ptrData;

            _rows = m._rows;
            _cols = m._cols;

            m._rows = 0;
            m._cols = 0;
            m._ptrData = nullptr;

            //std::cout << "Matrix::move constructor \n";
        }
        ~Matrix()
        {
            for (int i = 0; i < _rows; ++i)
                if (_ptrData != nullptr && _ptrData[i] != nullptr)
                    delete[] _ptrData[i];
            if (_ptrData != nullptr)
                delete[] _ptrData;
            //std::cout << "Matrix::destructor \n";
        }

        Matrix &operator=(const Matrix &m)
        {
            if (this == &m)
                return *this;

            if (_rows != m._rows || _cols != m._cols)
            {
                for (int i = 0; i < _rows; ++i)
                    delete[] _ptrData[i];
                delete[] _ptrData;

                _rows = m._rows;
                _cols = m._cols;
                _ptrData = new double *[_rows];
                for (int i = 0; i < _rows; ++i)
                    _ptrData[i] = new double[_cols];
            }

            for (int i = 0; i < _rows; ++i)
                for (int j = 0; j < _cols; ++j)
                    _ptrData[i][j] = m._ptrData[i][j];

            //std::cout << "Matrix::operator = \n";
            return *this;
        }
        Matrix &operator=(Matrix &&m)
        {
            if (this == &m)
                return *this;

            std::swap(_ptrData, m._ptrData);
            std::swap(_rows, m._rows);
            std::swap(_cols, m._cols);

            //std::cout << "Matrix::move operator = \n";
            return *this;
        }

        double *operator[](int i)
        {
            return _ptrData[i];
        }

        int RowNum() const { return _rows; }
        int ColNum() const { return _cols; }

        Matrix operator+(const Matrix &other)
        {
            //std::cout << "Matrix::operator + START \n";

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
                        temp._ptrData[i][j] = other._ptrData[i][j] + _ptrData[i][j];
            }
            //std::cout << "Matrix::operator + END \n";
            return temp;
        }

        Matrix operator-(const Matrix &other)
        {
            //std::cout << "Matrix::operator + START \n";

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
                        temp._ptrData[i][j] =  _ptrData[i][j] - other._ptrData[i][j];
            }
            //std::cout << "Matrix::operator + END \n";
            return temp;
        }

        Matrix  operator*( const Matrix &b ) const
        {
            Matrix	ret(RowNum(), b.ColNum());

            if( ColNum() == b.RowNum() )
            {
                for( int i=0; i<ret.RowNum(); i++ )
                    for( int j=0; j<ret.ColNum(); j++ )
                    {
                        ret._ptrData[i][j] = 0;
                        for(int k=0; k<ColNum(); k++ )
                            ret._ptrData[i][j] += _ptrData[i][k] * b._ptrData[k][j];
                    }
            }
            else
            {				// krive dimenzije matrice
            }

            return	ret;
        }        

        VectorN	operator*( VectorN &b )
        {
            int			i, j;
            VectorN	ret(RowNum());

            if( ColNum() == b.size() )
            {
                for( i=0; i<RowNum(); i++ )
                {
                    ret[i] = 0;
                    for( j=0; j<ColNum(); j++ )
                        ret[i] += _ptrData[i][j] * b[j];
                }
            }
            else
            {
                std::cout << "Krive dimenzije kod mnozenja matrice i vektora !!!";
            }

            return ret;
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

        void Print()
        {
            std::cout << "Rows: " << _rows << "  Cols: " << _cols << std::endl;

            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _cols; j++)
                {
                    std::cout << std::setw(10) << std::setprecision(3) << _ptrData[i][j] << ", ";
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

#endif