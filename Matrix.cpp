#include "Matrix.hpp"

#include <cassert>
#include <array>

Matrix::Matrix(int const nbColumn, int const nbRow) noexcept: m_nbColumn(nbColumn), m_nbRow(nbRow) 
{
    assert(nbColumn > 0);
    assert(nbRow > 0);

    int values[nbColumn*nbRow];
}

int Matrix::getDimension() const
{
    return m_nbColumn * m_nbRow;
}

int* Matrix::getColumn(int const column)
{
    int* columnVector {new int[m_nbRow]};
    int index = column * m_nbRow;

    for (int i {0}; i < m_nbRow; i++)
    {
        columnVector[i] = m_values[index + i];
    }
    return columnVector;
}


int* Matrix::getRow(int const row)
{
    int* rowVector {new int[m_nbColumn]};

    for (int i {0}; i < m_nbColumn; i++)
    {
        rowVector[i] = m_values[i * m_nbRow + row];
    }
    return rowVector;
}

Matrix operator+(Matrix const & m1, Matrix const & m2)
{
    assert((m1.m_nbRow == m2.m_nbRow) && (m1.m_nbColumn == m2.m_nbColumn));

    Matrix ret {m1.m_nbRow, m1.m_nbColumn};
    
    for (int i {0}; i < sizeof(ret.m_values); i++)
    {
        ret.m_values[i] = m1.m_values[i] + m2.m_values[i];
    }
    return ret;
}

Matrix operator-(Matrix const & m1, Matrix const & m2)
{
    assert((m1.m_nbRow == m2.m_nbRow) && (m1.m_nbColumn == m2.m_nbColumn));

    Matrix ret {m1.m_nbRow, m1.m_nbColumn};
    
    for (int i {0}; i < sizeof(ret.m_values); i++)
    {
        ret.m_values[i] = m1.m_values[i] - m2.m_values[i];
    }
    return ret;
}

Matrix operator*(Matrix const & m1, Matrix const & m2)
{
    assert(m1.m_nbColumn == m2.m_nbRow);

    Matrix ret {m1.m_nbRow, m2.m_nbColumn};

    int index = 0;
    for (int i {0}; i < (m1.m_nbRow * m2.m_nbColumn); i++)
    {

        int operation {0};
        for (int j {0}; j < m1.m_nbColumn - 1; j++)
        {
            for (int k {0}; k < m1.m_nbRow - 1; k++)
            {
                
            }
        }

    }
}