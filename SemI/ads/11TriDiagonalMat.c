//11 Tri Diagonal Matrix
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void getMatrix(unsigned int d, int matrix[d][d]);
void matrixAsList(unsigned int d, int matrix[d][d], int list[]);
void printList(unsigned int l, int list[l]);
void printMatrix(unsigned int d, int matrix[d][d]);

int main(void)
{
        system("clear");
        printf("11 Tri Diagonal Matrix\n\n");

        unsigned int d;
        printf("Number of rows and columns: ");
        scanf("%u", &d);
        int matrix[d][d];

        getMatrix(d, matrix);

        unsigned int l = d + (2*(d-1));
        int list[l];

        matrixAsList(d, matrix, list);
        
	printMatrix(d, matrix);

        printList(l, list);

        return(0);
}

void getMatrix(unsigned int d, int matrix[d][d])
{
        int rowNo, colNo;
        bool isRowBound = false, isColBound = false;
        printf("\nPopulate the matrix (%u integers)\n", d*d);
        for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
                {
                        isRowBound = rowNo < colNo + 2 && rowNo > colNo - 2;
                        isColBound = colNo < rowNo + 2 && colNo > rowNo - 2;
                        if(isRowBound && isColBound)
                                scanf("%d", &matrix[rowNo][colNo]);
                        else
                        {
                        	//we are out of bound in tri-diagonal matrix
			        printf("0 at [%d][%d]\n", rowNo, colNo);
                                matrix[rowNo][colNo] = 0;
                        }
                }
        }
        return;
}

void matrixAsList(unsigned int d, int matrix[d][d], int list[])
{
        int rowNo, colNo;
	unsigned int listIndex = 0;
        bool isRowBound = false, isColBound = false;
        for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
                {
                        isRowBound = rowNo < colNo + 2 && rowNo > colNo - 2;
                        isColBound = colNo < rowNo + 2 && colNo > rowNo - 2;
                        if(isRowBound && isColBound)
                        {
                                list[listIndex] = matrix[rowNo][colNo];
                                listIndex++;
                        }
                        //else we are out of bound in tri-diagonal matrix
                }
        }
        return;
}

void printList(unsigned int l, int list[l])
{
        unsigned int i;
        printf("\nMatrix as list :\n");
        for(i = 0; i < l; i++)
		printf("%d\t", list[i]);
        printf("\n");
        return;
}

void printMatrix(unsigned int d, int matrix[d][d])
{
        unsigned int rowNo, colNo;
        printf("\nOriginal Matrix :\n");
        for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
			printf("%d\t", matrix[rowNo][colNo]);
                printf("\n");
        }
        return;
}
