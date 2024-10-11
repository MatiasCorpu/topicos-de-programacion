#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TODO_OK 0
#define ERR_ARCH 1
#define ERR_LINEA_LARGA 2
#define OFFLINE 3
#define DUPLICADO 4


#define CAP_MAX_VEC_ARCH 50
#define CAP_MAX_VEC_MOST 50

#define TAM_MAX_LINEA 400

#define CAMPO_FECHA 12
#define CAMPO_CODSS 8
#define CAMPO_TEMP 6
#define CAMPO_ESTADO 12

#define ES_ESPACIO(c) (c == ' ' ? true : false)

typedef int (*Comparar)(void *, void *);

typedef struct
{
    void *vec;
    int ce;
    int cap;
    size_t tamElem;
} Vector;

typedef struct
{
    char codigo[CAMPO_CODSS];
    float temperatura;
    char estado[CAMPO_ESTADO];
} TemperaturaSensor;

bool vectorCrear(Vector *vec, int cap, size_t tamElem);
void vectorDestruir(Vector *vec);
void *vectorBusquedaBinaria(Vector *vec, void *elem, Comparar cmp);
int vectorInserterOrdenado(Vector *vec, void *elem, Comparar cmp);

char *trim(char *str);
int cmpCodSensor (void *a, void *b);
void vectorMostrar(Vector *vec);
int copiaLineaEnEstructura(TemperaturaSensor *ts, char *linea);
int procesarVector(Vector *vecArchivo, Vector *vecMostrar);
int informePromedioTempDeSensores(const char *nomArchivo);
#endif // FUNCIONES_H_INCLUDED
