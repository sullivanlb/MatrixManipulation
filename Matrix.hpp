#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string>
#include <cassert>

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
        int nbRow() const noexcept;
        int nbColumn()const noexcept;

        friend Matrix operator+(Matrix const & m1, Matrix const & m2);
        friend Matrix operator-(Matrix const & m1, Matrix const & m2);
        friend Matrix operator*(Matrix const & m1, Matrix const & m2);
        friend Matrix operator*(Matrix const & m1, int value);
        int& operator()(int column, int row) const ;
        friend std::ostream& operator<<(std::ostream & stream, Matrix const & m1);

};

#endif //MATRIX_HPP

