#include "Matrix.hpp"

Matrix::Matrix(std::size_t rows, std::size_t columns, int initial_value)
  : m_nb_row(rows), m_nb_column(columns), m_values(rows * columns, initial_value)
{
    assert(m_nb_row > 0 && m_nb_column > 0 && "We can't have a Matrix of dimension zero.");
}

std::size_t Matrix::offset(std::size_t row, std::size_t column) const noexcept
{
    assert(row < m_nb_row && "Invalid asked row.");
    assert(column < m_nb_column && "Invalid asked column.");
    return column * m_nb_row + row;
}

int const & Matrix::operator()(std::size_t x, std::size_t y) const
{
    return m_values[offset(x, y)];
}

int& Matrix::operator()(std::size_t x, std::size_t y)
{
    return m_values[offset(x, y)];
}

Matrix& Matrix::operator+=(Matrix const & matrix)
{
    assert(nb_row() == matrix.nb_row() && nb_column() == matrix.nb_column() && "Impossible to add two matrices of different sizes.");
    for (std::size_t i { 0 }; i < nb_row(); ++i)
    {
        for (std::size_t j { 0 }; j < nb_column(); ++j)
        {
            (*this)(i, j) += matrix(i, j);
        }
    }
    return *this;
}

Matrix operator+(Matrix lhs, Matrix const & rhs)
{
    lhs += rhs;
    return lhs;
}

Matrix& Matrix::operator*=(int multiplicator)
{
    for (std::size_t i { 0 }; i < nb_row(); ++i)
    {
        for (std::size_t j { 0 }; j < nb_column(); ++j)
        {
            (*this)(i, j) *= multiplicator;
        }
    }
    return *this;
}

Matrix operator*(Matrix matrix, int multiplicator)
{
    matrix *= multiplicator;
    return matrix;
}

Matrix operator*(int multiplicator, Matrix matrix)
{
    return matrix * multiplicator;
}

Matrix& Matrix::operator*=(Matrix const & matrix)
{
    Matrix copy { *this * matrix };
    std::swap(*this, copy);
    return *this; 
}

Matrix operator*(Matrix const & lhs, Matrix const & rhs)
{
    assert(lhs.nb_column() == rhs.nb_row() && "The number of columns in the Multiplied Matrix must be equal to the number of rows in the Multiplied Matrix.");

    Matrix copy { lhs.nb_row(), rhs.nb_column() };
    for (std::size_t i { 0 }; i < copy.nb_row(); ++i)
    {
        auto const row_courante { lhs.row(i).m_values };
        for (std::size_t j { 0 }; j < copy.nb_column(); ++j)
        {
            auto const column_courante { rhs.column(j).m_values };
            const int valeur { std::inner_product(std::begin(row_courante), std::end(row_courante), std::begin(column_courante), 0) };
            copy(i, j) = valeur;
        }
    }

    return copy;
}

std::ostream& operator<<(std::ostream & stream, Matrix const & matrix)
{
    for (std::size_t i { 0 }; i < matrix.nb_row(); ++i)
    {
        for (std::size_t j { 0 }; j < matrix.nb_column(); ++j)
        {
            stream << matrix(i, j) << " ";
        }
        stream << "\n";
    }
    return stream;
}

Matrix Matrix::row(std::size_t index_row) const
{
    assert(index_row < nb_row() && "The index required for the row is larger than the size of the Matrix.");

    Matrix matrix_row { 1, nb_column() };
    for (std::size_t j { 0 }; j < nb_column(); ++j)
    {
        matrix_row(0, j) = (*this)(index_row, j);
    }
    return matrix_row;
}

Matrix Matrix::column(std::size_t index_column) const
{
    assert(index_column < nb_column() && "The index required for the column is larger than the Matrix dimension.");

    Matrix matrix_column { nb_row(), 1 };
    for (std::size_t i { 0 }; i < nb_row(); ++i)
    {
        matrix_column(i, 0) = (*this)(i, index_column);
    }
    return matrix_column;
}

Matrix Matrix::transpose() const
{
    Matrix transposee { nb_column(), nb_row() };
    for (std::size_t i { 0 }; i < nb_row(); ++i)
    {
        for (std::size_t j { 0 }; j < nb_column(); ++j)
        {
            transposee(j, i) = (*this)(i, j);
        }
    }

    return transposee;
}

std::size_t Matrix::nb_row() const noexcept
{
    return m_nb_row;
}

std::size_t Matrix::nb_column() const noexcept
{
    return m_nb_column;
}