#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix{
    private:
        int const m_nbColumn;
        int const m_nbRow;
        int* m_values;

    public:
        Matrix() = delete;
        Matrix(Matrix const &m1) = default;
        Matrix(int const nbColumn, int const nbRow) noexcept;
        int getDimension() const;
        int* getColumn(int const column) const;
        int* getRow(int const row) const;

        friend Matrix operator+(Matrix const & m1, Matrix const & m2);
        friend Matrix operator-(Matrix const & m1, Matrix const & m2);
        friend Matrix operator*(Matrix const & m1, Matrix const & m2);
        friend Matrix operator*(Matrix const & m1, int value);
        friend Matrix operator/(Matrix const & m1, Matrix const & m2);
        Matrix operator()(int column, int row);
        Matrix operator<<(Matrix const & m1);

};

#endif //MATRIX_HPP

