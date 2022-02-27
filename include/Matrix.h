namespace MML
{
    class Matrix
    {
    public:
        Matrix() : rows_(0), cols_(0)
        {
            p = nullptr;
        }
        Matrix(int rows, int cols) : rows_(rows), cols_(cols)
        {
            p = new double *[rows_];
            for (int i = 0; i < rows_; ++i)
                p[i] = new double[cols_];
            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                    p[i][j] = 0;
                }
            }
            cout << "constructor \n";
        }
        Matrix(const Matrix& copy) : rows_(m.rows_), cols_(m.cols_)
        {
            p = new double *[rows_];
            for (int i = 0; i < rows_; ++i)
                p[i] = new double[cols_];
            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                    p[i][j] = m.p[i][j];
                }
            }
            cout << "copy constructor \n";
        }
        Matrix(Matrix&& m)
        {
            p = m.p;

            rows_ = m.rows_;
            cols_ = m.cols_;

            m.rows_ = 0;
            m.cols_ = 0;
            m.p = nullptr;

            cout << "move constructor \n";
        }
        ~Matrix()
        {
            for (int i = 0; i < rows_; ++i) {
                if (p != nullptr && p[i] != nullptr)
                    delete[] p[i];
            }
            if (p != nullptr)
                delete[] p;
            cout << "destructor \n";
        }

        Matrix& operator=(const Matrix& m)
        {
            if (this == &m) {
                return *this;
            }

            if (rows_ != m.rows_ || cols_ != m.cols_) {
                for (int i = 0; i < rows_; ++i) {
                    delete[] p[i];
                }
                delete[] p;

                rows_ = m.rows_;
                cols_ = m.cols_;
                p = new double *[rows_];
                for (int i = 0; i < rows_; ++i)
                    p[i] = new double[cols_];
            }

            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                    p[i][j] = m.p[i][j];
                }
            }
            cout << "operator = \n";
            return *this;
        }
        Matrix& operator=(Matrix&& m);

        Matrix  operator+(const Matrix &other);


    private:
        int rows_;
        int cols_;
        double **p;
    };
}