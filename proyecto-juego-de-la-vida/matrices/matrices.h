#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILAS_MAX 50
#define COLUMNAS_MAX 50

void **matrizCrear(int filas, int columnas, size_t tamElem);
void matrizDestruir(void **matriz, int filas);

void matrizInicializarEnCero(int **matriz, int filas, int columnas);
void matrizMostrar(int **matriz, int filas, int columnas);
void matrizCopiarEnElCentro(int **mtDest, int mtOrig[][COLUMNAS_MAX], int fDest, int cDest, int fOrig, int cOrig);
int matrizInicializarConMenu(int **matriz, int filas, int columnas);
int cantidadVecinosVivos(int **matriz, int bordeDer, int bordeInf, int i, int j);
void matrizProcesar(int **matriz, int filas, int columnas);

void inicioPlaneador(int **matriz, int filas, int columnas);
void inicioSapo(int **matriz, int filas, int columnas);
void inicioPulsar(int **matriz, int filas, int columnas);
void inicioCanion(int **matriz, int filas, int columnas);
void inicioVortice(int **matriz, int filas, int columnas);

#endif // MATRICES_H_INCLUDED
