#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void **matrixCreate(int rows, int columns, size_t sizeElement);
void matrixDestroy(void **matrix, int rows);

void matrixShow(const int **matrix, int rows, int columns);
void matrixInit(int **matrix, int rows, int columns, int value);
int matrixTrace(const int **matrix, int n);
int sumSecondaryDiagonal(const int **matrix, int n);
int sumAboveMainDiagonal(const int **matrix, int n);
int sumBelowMainDiagonal(const int **matrix, int n);
int sumAboveSecondaryDiagonal(const int **matrix, int n);
int sumBelowSecondaryDiagonal(const int **matrix, int n);
bool isIdentityMatrix(const int **matrix, int n);
bool isSymmetricMatrix(const int **matrix, int n);
int **sumeMatrix(const int **matrix1, const int **matrix2, int rows, int columns);
int **matrixProduct(const int **matrix1, const int **matrix2, int rows1, int columns1Rows2, int columns2);
void **transposeMatrix(const void **matrix, int rows, int columns, size_t sizeElement);

#endif // MATRIZ_H_INCLUDED