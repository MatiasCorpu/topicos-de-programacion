#include "matrices.h"

// constructores y destructores
void **matrizCrear(int filas, int columnas, size_t tamElem)
{
    void **matriz = malloc(filas * sizeof(void *)); // filas
    if (matriz == NULL)
        return NULL;

    for (int i = 0; i < filas; i++) // columnas
    {
        matriz[i] = malloc(columnas * tamElem);

        if (matriz[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(matriz[j]);

            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void matrizDestruir(void **matriz, int filas)
{
    for (int i = 0; i < filas; i++)
        free(matriz[i]);

    free(matriz);
}

// funciones de proceso
void matrizInicializarEnCero(int **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = 0;
}

void matrizMostrar(int **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            printf("%d ", matriz[i][j]);
    }
}

void matrizCopiarEnElCentro(int **mtDest, int mtOrig[][COLUMNAS_MAX], int fDest, int cDest, int fOrig, int cOrig)
{
    // Calcular el desplazamiento para centrar la matriz chica en la grande
    int offsetFila = (fDest - fOrig) / 2;
    int offsetColumna = (cDest - cOrig) / 2;

    // Copiar la matriz chica en el centro de la grande
    for (int i = 0; i < fOrig; i++)
    {
        for (int j = 0; j < cOrig; j++)
        {
            mtDest[offsetFila + i][offsetColumna + j] = mtOrig[i][j];
        }
    }
}

int matrizInicializarConMenu(int **matriz, int filas, int columnas)
{
    matrizInicializarEnCero(matriz, filas, columnas);

    int opcion;

    printf("\n1. Planeador\n2. Sapo\n3. Pulsar\n4. Canion de planeadores\n5. Vortice\n");
    printf("\n\nOpcion:  ");
    scanf("%d", &opcion);
    fflush(stdin);

    switch (opcion)
    {
    case 1:
        inicioPlaneador(matriz, filas, columnas);
        break;
    case 2:
        inicioSapo(matriz, filas, columnas);
        break;
    case 3:
        inicioPulsar(matriz, filas, columnas);
        break;
    case 4:
        inicioCanion(matriz, filas, columnas);
        break;
    case 5:
        inicioVortice(matriz, filas, columnas);
        break;
    default:
        printf("\n\t------OPCION NO VALIDA-----\n");
        return 1; // done = 1;
    }

    return 0;
}

int cantidadVecinosVivos(int **matriz, int bordeDer, int bordeInf, int i, int j)
{
    int contador = 0;

    int topeLateralDer = j < (bordeDer - 1) ? (j + 1) : j;
    int topeLateralIzq = j > 0 ? (j - 1) : j;
    int topeSuperior = i > 0 ? (i - 1) : i;
    int topeInferior = i < (bordeInf - 1) ? (i + 1) : i;

    for (int l = topeSuperior; l <= topeInferior; l++)
    {
        for (int m = topeLateralIzq; m <= topeLateralDer; m++)
        {
            // Si la celda no es la actual y es una celda viva o anteriormente viva
            if (!(l == i && m == j) && ((matriz[l][m] == 1) || (matriz[l][m] == -1)))
                contador++;
        }
    }

    return contador;
}

void matrizProcesar(int **matriz, int filas, int columnas)
{
    /*
    0: Celda muerta.
    1: Celda viva.
    2: Celda que estaba muerta, pero va a nacer.
    -1: Celda que estaba viva, pero va a morir.
    */

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int cantVivos = cantidadVecinosVivos(matriz, FILAS_MAX, COLUMNAS_MAX, i, j);

            if (matriz[i][j] == 0 && cantVivos == 3) // va a nacer
                matriz[i][j] = 2;

            else if (matriz[i][j] == 1)
            {
                if (cantVivos < 2 || cantVivos > 3)
                    matriz[i][j] = -1; // va a morir
                else
                    matriz[i][j] = 1; // sigue vivo
            }
        }
    }

    // Segundo recorrido: Actualizamos los valores finales
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] == 2)       // Si estaba marcada para nacer
                matriz[i][j] = 1;        // Se convierte en célula viva
            else if (matriz[i][j] == -1) // Si estaba marcada para morir
                matriz[i][j] = 0;        // Se convierte en célula muerta
        }
    }
}

// Funciones de inicio de patrones
void inicioPlaneador(int **matriz, int filas, int columnas)
{
    int planeador[5][COLUMNAS_MAX] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    matrizCopiarEnElCentro(matriz, planeador, filas, columnas, 5, 5);
}

void inicioSapo(int **matriz, int filas, int columnas)
{
    int sapo[5][COLUMNAS_MAX] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    matrizCopiarEnElCentro(matriz, sapo, filas, columnas, 5, 5);
}

void inicioPulsar(int **matriz, int filas, int columnas)
{
    int pulsar[17][COLUMNAS_MAX] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    matrizCopiarEnElCentro(matriz, pulsar, filas, columnas, 17, 17);
}

void inicioCanion(int **matriz, int filas, int columnas)
{
    int canion[][COLUMNAS_MAX] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    matrizCopiarEnElCentro(matriz, canion, filas, columnas, 9, 37);
}

void inicioVortice(int **matriz, int filas, int columnas)
{
    int vortice[][COLUMNAS_MAX] = {
        {1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1}};

    matrizCopiarEnElCentro(matriz, vortice, filas, columnas, 9, 9);
}