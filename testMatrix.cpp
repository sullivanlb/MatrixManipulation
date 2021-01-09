#include "Matrix.hpp"

void test_addition()
{
    Matrix m1 { 2, 3 };
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 3;
    m1(1, 1) = 4;
    m1(1, 2) = 6;

    Matrix m2 { 2, 3 };
    m2(0, 0) = 0;
    m2(0, 1) = 4;
    m2(0, 2) = 9;
    m2(1, 0) = 4;
    m2(1, 1) = -7;
    m2(1, 2) = 1;

    Matrix result { 2, 3 };
    result(0, 0) = 1;
    result(0, 1) = 6;
    result(0, 2) = 12;
    result(1, 0) = 7;
    result(1, 1) = -3;
    result(1, 2) = 7;

    Matrix const addition { m1 + m2 };

    assert(addition.nbRow() == result.nbRow() && "The addition isn't correct.");
    assert(addition.nbColumn() == result.nbColumn() && "The addition isn't correct.");
    for (int i { 0 }; i < addition.nbRow(); ++i)
    {
        for (int j { 0 }; j < addition.nbColumn(); ++j)
        {
            assert(result(i, j) == addition(i, j) && "The addition isn't correct.");
        }
    }
}

void test_multiplication_integer()
{
    Matrix m1 { 2, 3 };
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 3;
    m1(1, 1) = 4;
    m1(1, 2) = 6;

    Matrix result { 2, 3 };
    result(0, 0) = 2;
    result(0, 1) = 4;
    result(0, 2) = 6;
    result(1, 0) = 6;
    result(1, 1) = 8;
    result(1, 2) = 12;

    Matrix const multiplication { m1 * 2 };

    assert(result.nbRow() == multiplication.nbRow() && "The multiplication by an integer isn't correct.");
    assert(result.nbColumn() == multiplication.nbColumn() && "The multiplication by an integer isn't correct.");
    for (int i { 0 }; i < multiplication.nbRow(); ++i)
    {
        for (int j { 0 }; j < multiplication.nbColumn(); ++j)
        {
            assert(result(i, j) == multiplication(i, j) && "The multiplication by an integer isn't correct.");
        }
    }
}

void test_multiplication_Matrix()
{
    Matrix m1 { 2, 3 };
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 3;
    m1(1, 1) = 4;
    m1(1, 2) = 6;

    Matrix m2 { 3, 2 };
    m2(0, 0) = 0;
    m2(0, 1) = 4;
    m2(1, 0) = 4;
    m2(1, 1) = -7;
    m2(2, 0) = 9;
    m2(2, 1) = 1;

    Matrix result { 2, 2 };
    result(0, 0) = 35;
    result(0, 1) = -7;
    result(1, 0) = 70;
    result(1, 1) = -10;

    Matrix const multiplication { m1 * m2 };

    assert(result.nbRow() == multiplication.nbRow() && "The multiplication by a Matrix isn't correct.");
    assert(result.nbColumn() == multiplication.nbColumn() && "The multiplication by a Matrix isn't correct.");
    for (int i { 0 }; i < multiplication.nbRow(); ++i)
    {
        for (int j { 0 }; j < multiplication.nbColumn(); ++j)
        {
            assert(result(i, j) == multiplication(i, j) && "The multiplication by a Matrix isn't correct.");
        }
    }
}

void test_toString()
{
    Matrix m1 { 2, 2 };
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(1, 0) = 3;
    m1(1, 1) = 3;

    Matrix m2 { 2, 2 };
    m2(0, 0) = 0;
    m2(0, 1) = 4;
    m2(1, 0) = 4;
    m2(1, 1) = -7;

    std::cout << m1 << "\n";
    std::cout << m1 + m2 << "\n";
    std::cout << m1 + m2 + m2 << "\n";
}

int main()
{
    test_addition();
    test_multiplication_integer();
    test_multiplication_Matrix();
    test_toString();

    return 0;
}