#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

// mensaje para poner en el commit de la libreria macros, en ingles
// "I added macros for mathematical and character operations"
// "Agrego macros para operaciones matematicas y de caracteres"

#include <stdio.h>
#include <stdlib.h>

#define ROUND(x) (x - (int)x >= 0.5 ? (int)x + 1 : (int)x)
#define ABSOLUTE_VALUE(x) (x > 0 ? x : x * (-1))
#define INTEGER_PART(x) (int)x
#define DECIMAL_PART(x) (x - (int)x)
#define IS_EVEN(x) (x % 2 == 0)
#define IS_LETTER(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define IS_DIGIT(c) (c >= '0' && c <= '9')
#define IS_UPPERCASE(c) (c >= 'A' && c <= 'Z')
#define IS_LOWERCASE(c) (c >= 'a' && c <= 'z')
#define IS_WHITESPACE(c) (c == ' ')
#define TO_UPPERCASE(c) ((c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c)
#define TO_LOWERCASE(c) ((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c)
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)
#define IS_POWER_OF(x, y) (x % y == 0)
#define SWAP_VALUES(p1, p2) \
    {                       \
        int temp = *p1;     \
        *p1 = *p2;          \
        *p2 = temp;         \
    }

#endif // MACROS_H_INCLUDED
