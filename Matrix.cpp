#include "Matrix.hpp"

#include <cassert>
#include <array>

Matrix::Matrix(int const nbColumn, int const nbRow) noexcept: m_nbColumn(nbColumn), m_nbRow(nbRow) 
{
    assert(nbColumn > 0);
    assert(nbRow > 0);

    int values[nbColumn*nbRow];
}

int Matrix::getDimension()
{
    return m_nbColumn * m_nbRow;
}

int* getColumn(int const column)
{
    
}