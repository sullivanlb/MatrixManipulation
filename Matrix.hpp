#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{
    private:
        int const m_nbColumn;
        int const m_nbRow;
        int* m_values;

    public:
        Matrix() = delete;
        Matrix(Matrix const &m1) = default;
        Matrix(int const nbColumn, int const nbRow) noexcept;
        int getDimension();
        int* getColumn(int const column);
        int* getRow(int const row);

        Matrix operator+(Matrix const m1);
        Matrix operator-(Matrix const m1);
        Matrix operator*(Matrix const m1);
        Matrix operator/(Matrix const m1);
        Matrix operator()(int column, int row);

};

#endif //MATRIX_HPP

