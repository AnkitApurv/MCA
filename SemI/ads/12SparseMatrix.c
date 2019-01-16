//12 Sparse Matrix
#include <stdio.h>
#include <stdlib.h>

struct matrixElement
{
        unsigned int row;
        unsigned int col;
        int val;
};

void getMatrix(int d, int matrix[][d]);
void matrixAsList(int d, int matrix[][d], struct matrixElement list[]);
void printList(struct matrixElement list[]);
void printMatrix(struct matrixElement list[]);

int main(void)
{
        system("clear");
        printf("12 Sparse Matrix\n\n");

        int d = 0;
        printf("Number of rows and columns: ");
        scanf("%d", &d);
        int matrix[d][d];

        getMatrix(d, matrix);

        struct matrixElement list[d*d];

        matrixAsList(d, matrix, list);

        printList(list);

        printMatrix(list);

        return(0);
}

void getMatrix(int d, int matrix[][d])
{
        int rowNo = 0, colNo = 0;
        printf("\nPopulate the matrix (%d integers)\n", d*d);
        for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
                {
                        scanf("%d", &matrix[rowNo][colNo]);
                }
        }
        return;
}

void matrixAsList(int d, int matrix[][d], struct matrixElement list[])
{
        int listIndex = 1;
        int rowNo, colNo;
// head, has matrix dimension and total non zero values, for reconstruction
        list[0].row = d;
        list[0].col = d;
        list[0].val = 0;
        for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
                {
                        if(matrix[rowNo][colNo] != 0)
                        {
                                list[listIndex].val = matrix[rowNo][colNo];
                                list[listIndex].row = rowNo;
                                list[listIndex].col = colNo;
                                list[0].val++;
                                listIndex++;
                        }
                        //else 0 in sparse matrix
                }
        }
        return;
}

void printList(struct matrixElement list[])
{
        int i;
        printf("\nMatrix as list :\n");
        for(i = 1; i <= list[0].val; i++)
        {
                printf("%d\t", list[i].val);
        }
        printf("\n");
        return;
}

void printMatrix(struct matrixElement list[])
{
        unsigned int rowNo, colNo, size;
        rowNo = list[0].row;
        colNo = list[0].col;
        int matrix[rowNo][colNo];
        printf("\nOriginal Matrix :\n");
        //initializing
        for(rowNo = 0; rowNo < list[0].row; rowNo++)
        {
                for(colNo = 0; colNo < list[0].col; colNo++)
                {
                        matrix[rowNo][colNo] = 0;
                }
        }
        //reconstructing
        for(size = 1; size <= list[0].val; size++)
        {
                matrix[list[size].row][list[size].col] = list[size].val;
        }
        //printing
        for(rowNo = 0; rowNo < list[0].row; rowNo++)
        {
                for(colNo = 0; colNo < list[0].col; colNo++)
                {
                        printf("%d\t", matrix[rowNo][colNo]);
                }
                printf("\n");
        }
        return;
}
