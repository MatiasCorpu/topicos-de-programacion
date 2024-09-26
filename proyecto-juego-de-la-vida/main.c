#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#include <SDL_main.h>
#endif

#include <SDL.h>
#include "matrices/matrices.h"

#define TAMANIO_CELDA 10
#define ANCHO_VENTANA 960
#define ALTO_VENTANA 540

void drawFilledCircle(SDL_Renderer *renderer, int cx, int cy, int radius);
void dibujarMatrizEnElRenderer(int **matriz, int filas, int columnas, SDL_Renderer *renderer, SDL_Rect *fillRect);

int main(int argc, char *argv[])
{
    unsigned char done;
    int k;
    // Mucha de esta parametrizacion puede venir por linea de comando!!
    int delay = 100;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event e;
    SDL_Rect fillRect;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("Juego de la vida",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              ANCHO_VENTANA,
                              ALTO_VENTANA,
                              SDL_WINDOW_SHOWN);
    if (!window)
    {
        SDL_Log("Error en la creacion de la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Creamos el lienzo
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_Log("No se ha podido crear el lienzo! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Creamos la matriz y la inicializamos
    int **matriz = (int **)matrizCrear(FILAS_MAX, COLUMNAS_MAX, sizeof(int));
    done = matrizInicializarConMenu(matriz, FILAS_MAX, COLUMNAS_MAX);

    while (!done) // Se puede parar tambien cuando no se observen cambios!
    {
        while (SDL_PollEvent(&e) != 0)
        {
            // Salida del usuario
            if (e.type == SDL_QUIT)
                done = 1;
        }

        // Se limpia la pantalla
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        // Dibujo de la matriz
        dibujarMatrizEnElRenderer(matriz, FILAS_MAX, COLUMNAS_MAX, renderer, &fillRect);
        matrizProcesar(matriz, FILAS_MAX, COLUMNAS_MAX);

        // Actualizacion del "lienzo"
        SDL_RenderPresent(renderer);
        k++;
        // SDL_UpdateWindowSurface(window);

        // Titulo/caption de la ventana
        // SDL_SetWindowTitle(window, "Porque no usar esto para poner alguna info del proceso?");
        SDL_Delay(delay);
    }

    // destruyo todos los elementos creados
    matrizDestruir((void *)matriz, FILAS_MAX);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void drawFilledCircle(SDL_Renderer *renderer, int cx, int cy, int radius)
{
    for (int y = -radius; y <= radius; y++)
        for (int x = -radius; x <= radius; x++)
            if (x * x + y * y <= radius * radius)
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
}

void dibujarMatrizEnElRenderer(int **matriz, int filas, int columnas, SDL_Renderer *renderer, SDL_Rect *fillRect)
{
    // para que este en el centro del lienzo
    int offsetX = (ANCHO_VENTANA - (columnas * TAMANIO_CELDA)) / 2;
    int offsetY = (ALTO_VENTANA - (filas * TAMANIO_CELDA)) / 2;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            // posicion carteciana // es para dibujar cuadrados
            fillRect->x = offsetX + i * TAMANIO_CELDA;
            fillRect->y = offsetY + j * TAMANIO_CELDA;
            // tamaño del cuadrado
            fillRect->w = TAMANIO_CELDA;
            fillRect->h = TAMANIO_CELDA;

            if (matriz[i][j] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 0x80, 0xFF, 0x80, 0xFF);
                // dibuja circulos
                drawFilledCircle(renderer, offsetX + j * TAMANIO_CELDA + TAMANIO_CELDA / 2, offsetY + i * TAMANIO_CELDA + TAMANIO_CELDA / 2, TAMANIO_CELDA / 2);
                // diuja cuadrados
                // SDL_RenderFillRect(renderer, fillRect);
            }
        }
    }
}
