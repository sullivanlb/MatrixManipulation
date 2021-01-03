#include "Matrix.hpp"

#include <cassert>
#include <array>

Matrix::Matrix(int const nbColumn, int const nbRow) : m_nbColumn(nbColumn), m_nbRow(nbRow){
    assert(nbColumn > 0);
    assert(nbRow > 0);

    //std::array<int, (this->m_nbRow*this->m_nbColumn)> values;
}