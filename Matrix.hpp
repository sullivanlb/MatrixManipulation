#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrice{
    private:
        int const m_nbColumn;
        int const m_nbRow;
        int* m_values;

    public:
        Matrice(int const nbColumn, int const nbRow);
        Matrice copy(Matrice const m1);
        int getElement(int const column, int const row);
        int setElement(int const column, int const row, int const value);
        int getDimension();
        int* getColumn(int const column);
        int* getRow(int const row);

        Matrice operator+(Matrice const m1);
        Matrice operator-(Matrice const m1);
        Matrice operator*(Matrice const m1);
        Matrice operator/(Matrice const m1);

};

#endif //MATRIX_HPP

