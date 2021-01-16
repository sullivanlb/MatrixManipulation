#ifndef Matrix_HPP
#define Matrix_HPP

#include <iosfwd>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>

/**
 * @brief Matrix Manipulation.
 */
class Matrix
{
public:
    Matrix(std::size_t row, std::size_t column, int initial_value = 0);
    Matrix(Matrix const & Matrix) = default;

    int const & operator()(std::size_t x, std::size_t y) const;
    int& operator()(std::size_t x, std::size_t y);
    
    Matrix& operator=(Matrix const & Matrix) = default;
    Matrix& operator*=(int multiplicator);
    Matrix& operator+=(Matrix const & Matrix);
    Matrix& operator*=(Matrix const & Matrix);

    friend Matrix operator+(Matrix m1, Matrix const & m2);
    friend Matrix operator*(Matrix m, int multiplicator);
    friend Matrix operator*(int multiplicator, Matrix m);
    friend Matrix operator*(Matrix const & m1, Matrix const & m2);
    friend std::ostream& operator<<(std::ostream & stream, Matrix const & Matrix);

    Matrix row(std::size_t index_row) const;
    Matrix column(std::size_t index_column) const;
    Matrix transpose() const;

    std::size_t nb_row() const noexcept;
    std::size_t nb_column() const noexcept;

private:
    std::size_t offset(std::size_t row, std::size_t column) const noexcept;

    std::size_t m_nb_row;
    std::size_t m_nb_column;
    std::vector<int> m_values;
};

#endif