//Author Name : Ankit Apurv
//Date : 10_9_18
//Week 05
//Program : 01 Matrix - friend operator overloading

const int n = 100;

#include <iostream>
using namespace std;

class Matrix
{
    private:
        unsigned int noRows, noCols;
        int val[n][n];

    public:
        void set(); //input
        void get(); //display
        friend Matrix operator +(Matrix m1, Matrix m2);
        friend Matrix operator -(Matrix m1, Matrix m2);
        friend bool operator ==(Matrix m1, Matrix m2);

        Matrix()
        {
            noRows = noCols = 0;
            val[noRows][noCols] = 0;
        }

        Matrix(unsigned int r, unsigned int c)
        {
            noRows = r;
            noCols = c;
            set();
        }

        ~Matrix() {}
};

void Matrix::set()
{
    //input
    cout << "\n";
    if(noRows == 0 || noCols == 0)
    {
        cout << "Rows : "; cin >> noRows;
        cout << "Columns : "; cin >> noCols;
    }
    for(unsigned int row=0; row<noRows; row++)
    {
        for(unsigned int col=0; col<noCols; col++)
        {
            cout << "[" << row << "][" << col << "] : ";
            cin >> val[row][col];
        }
    }
    return;
}

void Matrix::get()
{
    //display
    cout << "\n";
    for(unsigned int row=0; row<noRows; row++)
    {
        for(unsigned int col=0; col<noCols; col++)
        {
            cout << "[" << row << "][" << col << "] : " << val[row][col] << "\t";
        }
        cout << "\n";
    }
    return;
}

Matrix operator +(Matrix m1, Matrix m2)
{
    Matrix k;
    k.noRows = m1.noRows;
    k.noCols = m1.noCols;
    for(unsigned int row=0; row<k.noRows; row++)
        for(unsigned int col=0; col<k.noCols; col++)
            k.val[row][col] = m1.val[row][col] + m2.val[row][col];
    return(k);
}

Matrix operator -(Matrix m1, Matrix m2)
{
    Matrix k;
    k.noRows = m1.noRows;
    k.noCols = m1.noCols;
    for(unsigned int row=0; row<k.noRows; row++)
        for(unsigned int col=0; col<k.noCols; col++)
            k.val[row][col] = m1.val[row][col] - m2.val[row][col];
    return(k);
}

bool operator ==(Matrix m1, Matrix m2)
{
    return(m1.noRows == m2.noCols && m1.noRows == m2.noCols);
}

int main(void)
{
    Matrix m1, m2, m3, m4;
    m1.set();
    m2.set();
    if(m1 == m2)
    {
        m3 = m1 + m2;
        m4 = m1 - m2;
        m3.get();
        m4.get();
    }
    else
        cout << "Matrices are not equal\n";
    return(0);
}