#include <stdio.h>

//func to take matrix input from user
void inputmatrix(int matrix[2][2], char name)
{
    printf("\nEnter elements for matrix %c : ", name);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\nEnter element [%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//func to display matrix
void displaymatrix(int matrix[2][2], char name)
{
    printf("\nMatrix %c : \n ", name);
    for (int i = 0; i <2 ; i++)
    {
        for (int j = 0; j < 2 ; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//func to multiply two matrices
void multiplymatrices( int matrixA[2][2] , int matrixB[2][2] , int result[2][2] )
{
    //for getting result matrix = 0 for each element
    for (int i = 0; i < 2 ; i++)
    {
        for (int j = 0; j < 2 ; j++)
        {
            result[i][j] = 0;
        }
    }

    //matrix multi logic
    for (int i = 0; i < 2 ; i++)
    {
        for (int j = 0; j < 2 ; j++)
        {
            for (int k = 0; k < 2 ; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main()
{
    


    int matrixA[2][2], matrixB[2][2], result[2][2];

    //taking inputs
    inputmatrix(matrixA, 'A');
    inputmatrix(matrixB, 'B');

    //displaying matrices
    displaymatrix(matrixA, 'A');
    displaymatrix(matrixB, 'B');

    //multiplying matrices
    multiplymatrices(matrixA, matrixB , result);

    //final result
    displaymatrix(result, 'R');

    

    return 0;
}
