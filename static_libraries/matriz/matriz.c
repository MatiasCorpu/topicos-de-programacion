#include "matriz.h"

void **matrixCreate(int rows, int columns, size_t sizeElement)
{
    void **matrix = malloc(rows * sizeof(void *));
    if (matrix == NULL)
        return NULL;

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(columns * sizeElement);
        if (matrix[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(matrix[j]);

            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void matrixDestroy(void **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void matrixShow(const int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void matrixInit(int **matrix, int rows, int columns, int value)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = value;
}

int matrixTrace(const int **matrix, int n)
{
    int sume = 0;
    for (int i = 0; i < n; i++)
        sume += matrix[i][i];

    return sume;
}

int sumSecondaryDiagonal(const int **matrix, int n)
{
    int sume = 0;
    for (int i = 0; i < n; i++)
        sume += matrix[i][n - i - 1];

    return sume;
}

int sumAboveMainDiagonal(const int **matrix, int n)
{
    int sume = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            sume += matrix[i][j];

    return sume;
}

int sumBelowMainDiagonal(const int **matrix, int n)
{
    int sume = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            sume += matrix[i][j];

    return sume;
}

int sumAboveSecondaryDiagonal(const int **matrix, int n)
{
    int sume = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            sume += matrix[i][j];

    return sume;
}

int sumBelowSecondaryDiagonal(const int **matrix, int n)
{
    int sume = 0;
    for (int i = 1; i < n; i++)
        for (int j = n - i; j < n; j++)
            sume += matrix[i][j];

    return sume;
}

bool isIdentityMatrix(const int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][i] != 1 || (i != j && matrix[i][j] != 0))
                return false;

    return true;
}

bool isSymmetricMatrix(const int **matrix, int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (matrix[i][j] != matrix[j][i])
                return false;

    return true;
}

int **sumeMatrix(const int **matrix1, const int **matrix2, int rows, int columns)
{
    int **matrixSum = (int **)matrixCreate(rows, columns, sizeof(int));
    if (matrixSum == NULL)
        return NULL;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];

    return matrixSum;
}

int **matrixProduct(const int **matrix1, const int **matrix2, int rows1, int columns1Rows2, int columns2)
{
    int **matrix = (int **)matrixCreate(rows1, columns2, sizeof(int));
    if (matrix == NULL)
        return NULL;

    matrixInit(matrix, rows1, columns2, 0);

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            int sume = 0;

            for (int k = 0; k < columns1Rows2; k++)
                sume += matrix1[i][k] * matrix2[k][j];

            matrix[i][j] = sume;
        }
    }

    return matrix;
}