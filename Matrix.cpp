#include "Matrix.hpp"

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

int* Matrix::getColumn(int const column) const
{
    int* columnVector {new int[m_nbRow]};
    int index = column * m_nbRow;

    for (int i {0}; i < m_nbRow; i++)
    {
        columnVector[i] = m_values[index + i];
    }
    return columnVector;
}


int* Matrix::getRow(int const row) const
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

    int index {0};
    for (int i {0}; i < m2.m_nbColumn - 1; i++)
    {
        for (int j {0}; j < m1.m_nbRow - 1; j++)
        {
            int* row = m1.getRow(j);
            int* column = m2.getColumn(i);

            int total {0};
            for (int k {0}; k < sizeof(row); k++)
            {
                row[k] *= column[k];
                total += row[k];
            }
            ret.m_values[index] = total;
            index++;
        }
    }

    return ret;
}

Matrix operator*(Matrix const & m1, int value)
{
    Matrix ret {m1.m_nbRow, m1.m_nbColumn};

    for (int i {0}; i < (m1.m_nbRow * m1.m_nbColumn); i++)
    {
        ret.m_values[i] = m1.m_values[i] * value;
    }

    return ret;
}

int& Matrix::operator()(int column, int row) const
{
    return m_values[column * m_nbRow + row];
}

std::ostream& operator<<(std::ostream & stream, Matrix const & m1)
{

    for (int i {0}; i < m1.m_nbRow; i++)
    {
        for (int j {0}; j < m1.m_nbColumn; j++)
        {
            stream << m1.m_values[j * m1.m_nbRow + i] + ", ";
        }
        stream << "\r\n";
    }
    stream << ")";
}

int Matrix::nbRow() const noexcept
{
    return m_nbRow;
}

int Matrix::nbColumn() const noexcept
{
    return m_nbColumn;
}