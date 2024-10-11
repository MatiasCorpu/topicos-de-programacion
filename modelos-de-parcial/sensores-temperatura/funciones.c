#include "funciones.h"
#include <stdio.h>
#include <string.h>

// FUNCIONES VECTOR TDA
bool vectorCrear(Vector *vec, int cap, size_t tamElem)
{
    vec->vec = malloc(cap * tamElem);
    if (vec->vec == NULL)
        return false;

    vec->cap = cap;
    vec->ce = 0;
    vec->tamElem = tamElem;

    return true;
}

void vectorDestruir(Vector *vec)
{
    vec->cap = 0;
    vec->ce = 0;
    vec->tamElem = 0;
    free(vec->vec);
    vec->vec = NULL;
}

void *vectorBusquedaBinaria(Vector *vec, void *elem, Comparar cmp)
{
    void *izq = vec->vec;
    void *der = vec->vec + (vec->ce - 1) * vec->tamElem;
    void *med;

    while (izq <= der)
    {
        med = izq + ((der - izq) / (2 * vec->tamElem) * vec->tamElem);

        if (cmp(med, elem) == 0)
            return med;

        if (cmp(med, elem) < 0)
            izq = med + vec->tamElem;
        else
            der = med - vec->tamElem;
    }
    return NULL;
}

int vectorInserterOrdenado(Vector *vec, void *elem, Comparar cmp)
{
    void *izq = vec->vec;
    void *der = vec->vec + (vec->ce - 1) * vec->tamElem;
    void *med;

    while (izq <= der)
    {
        med = izq + ((der - izq) / (2 * vec->tamElem) * vec->tamElem);

        if (cmp(med, elem) < 0)
            izq = med + vec->tamElem;
        else
            der = med - vec->tamElem;
    }

    for (void *i = vec->vec + vec->ce * vec->tamElem; i > izq; i -= vec->tamElem)
    {
        memcpy(i, i - vec->tamElem, vec->tamElem);
    }

    memcpy(izq, elem, vec->tamElem);
    vec->ce++;
    return TODO_OK;
}

// FUNCIONES NO TDA

char *trim(char *str)
{
    char *ptr;

    while (ES_ESPACIO(*str))
        str++;

    ptr = str;

    while (!ES_ESPACIO(*ptr) && *ptr != '\0')
        ptr++;

    *ptr = '\0';

    return str;
}

int copiaLineaEnEstructura(TemperaturaSensor *ts, char *linea)
{
    // ej =  1719077360   DEV08 16.50     OFFLINE\n\0
    char *ptr = strchr(linea, '\n');
    if (ptr == NULL)
        return ERR_LINEA_LARGA;

    // copio el estado a la estructura
    *ptr = '\0';
    ptr -= CAMPO_ESTADO;
    sscanf(trim(ptr), "%s", ts->estado);

    // copio la temperatura a la estructura
    *ptr = '\0';
    ptr -= CAMPO_TEMP;
    sscanf(trim(ptr), "%f", &ts->temperatura);

    // copio el codigo a la estructura
    *ptr = '\0';
    ptr -= CAMPO_CODSS;
    sscanf(trim(ptr), "%s", ts->codigo);

    return TODO_OK;
}

int cmpCodSensor(void *a, void *b)
{
    TemperaturaSensor *x = (TemperaturaSensor *)a;
    TemperaturaSensor *y = (TemperaturaSensor *)b;
    return strcmp(x->codigo, y->codigo);
}

void vectorMostrar(Vector *vec)
{
    for(void *i = vec->vec; i < vec->vec + vec->ce * vec->tamElem; i += vec->tamElem)
    {
        TemperaturaSensor *ts = (TemperaturaSensor *)i;
        if(strcmp(ts->estado, "READY") == 0)
            printf("%s %f\n", ts->codigo, ts->temperatura);
        else
            printf("%s %s\n", ts->codigo, "-Sin informacion confiable-");
    }
}

int informePromedioTempDeSensores(const char *nomArchivo)
{
    FILE *arch = fopen(nomArchivo, "rt");
    if (arch == NULL)
        return ERR_ARCH;

    TemperaturaSensor ts;

    Vector vecArchivo;
    Vector vecMostrar;

    vectorCrear(&vecArchivo, CAP_MAX_VEC_ARCH, sizeof(ts));
    vectorCrear(&vecMostrar, CAP_MAX_VEC_MOST, sizeof(ts));

    char linea[TAM_MAX_LINEA];

    while (fgets(linea, TAM_MAX_LINEA, arch))
    {
        copiaLineaEnEstructura(&ts, linea);
        vectorInserterOrdenado(&vecArchivo, &ts, cmpCodSensor);
    }

    fclose(arch);

    procesarVector(&vecArchivo, &vecMostrar);

    vectorMostrar(&vecMostrar);
    vectorDestruir(&vecArchivo);
    vectorDestruir(&vecMostrar);
    return TODO_OK;
}

int procesarVector(Vector *vecArchivo, Vector *vecMostrar)
{
    TemperaturaSensor *act = (TemperaturaSensor *)vecArchivo->vec;
    TemperaturaSensor *ult = (TemperaturaSensor *)vecArchivo->vec + (vecArchivo->ce - 1);

    TemperaturaSensor *vec = (TemperaturaSensor *)vecMostrar->vec;

    while (act <= ult)
    {
        strcpy(vec->codigo, act->codigo);
        strcpy(vec->estado, act->estado);

        float sumaTemperatura = 0;
        int contador = 0;

        if (strcmp(vec->estado, "READY") == 0)
        {
            sumaTemperatura += act->temperatura;
            contador++;
        }

        act++;

        while (act <= ult && strcmp(vec->codigo, act->codigo) == 0)
        {
            if (strcmp(act->estado, "READY") == 0)
            {
                sumaTemperatura += act->temperatura;
                contador++;
                
                if (strcmp(vec->estado, "OFFLINE") == 0)
                    strcpy(vec->estado, "READY");
            }
            act++;
        }

        if (contador > 0)
            vec->temperatura = sumaTemperatura / contador;
        else
            vec->temperatura = 0;

        vec++;
        vecMostrar->ce++;
    }

    return TODO_OK;
}