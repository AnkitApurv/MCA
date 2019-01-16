//09 Lower Triangular Matrix
#include <stdio.h>
#include <stdlib.h>

unsigned int addGP(unsigned int number);
void getMatrix(unsigned int d, int matrix[d][d]);
void matrixAsList(unsigned int d, int matrix[d][d], int list[]);
void printList(unsigned int l, int list[l]);
void printMatrix(unsigned int d, int matrix[d][d]);

int main(void)
{
        system("clear");
        printf("09 Lower Triangular Matrix\n");

        unsigned int d;
        printf("Number of rows and columns (square matrix) : ");
        scanf("%u", &d);
        int matrix[d][d];

        getMatrix(d, matrix);

        unsigned int l = addGP(d);
        int list[l];

        matrixAsList(d, matrix, list);

        printMatrix(d, matrix);

	printList(l, list);

        return(0);
}

void getMatrix(unsigned int d, int matrix[d][d])
{
        unsigned int rowNo, colNo;

        printf("\nPopulate the matrix (%u integers) :\n", d*d);
        for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
                {
                        if(rowNo >= colNo)
                                scanf("%d", &matrix[rowNo][colNo]);
			else
			{
                        //we are in the upper half of lower triangular matrix
                                printf("0 at [%u][%u]\n", rowNo, colNo);
                                matrix[rowNo][colNo] = 0;
			}

                }
        }
        return;
}

void matrixAsList(unsigned int d, int matrix[d][d], int list[])
{
        unsigned int rowNo, colNo, listIndex = 0;
        
	for(rowNo = 0; rowNo < d; rowNo++)
        {
                for(colNo = 0; colNo < d; colNo++)
                {
                        if(rowNo >= colNo)
                        {
                                list[listIndex] = matrix[rowNo][colNo];
                                listIndex++;
                        }
                        //else we are in the upper half of lower tri matrix
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

unsigned int addGP(unsigned int number)
{
        if(number <= 1)
                return number;
        else
                return number + addGP(number - 1);
}
