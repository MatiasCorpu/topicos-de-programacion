# Topicos de Programación

Este repositorio centraliza las prácticas, algoritmos y soluciones desarrolladas durante la cursada de Tópicos de Programación en la UNLaM. Contiene la implementación de bibliotecas genéricas y estructuras de datos robustas, aplicando los conceptos avanzados del lenguaje C aprendidos en la materia.

## Conocimientos y Temáticas Abordadas:
* Gestión de Memoria: Punteros (simples y dobles), memoria dinámica y aritmética de punteros.
* Programación Genérica: Funciones con void *, punteros a funciones y desarrollo de bibliotecas estáticas.
* Estructuras de Datos (TDA): Diseño de Tipos de Datos Abstractos y recursividad.
* Manejo de Información: Manipulación de archivos (texto y binarios), cadenas y matrices.
* Algoritmia: Algoritmos de ordenamiento (Selección, Inserción, Merge), búsqueda (secuencial y binaria) y manejo de errores.
* Optimización: Creación de macros avanzadas y normalización de datos.


## Índice

1. [Bibliotecas](#bibliotecas)
   1. [array](#array)
   2. [macros](#macros)
   3. [mathematics](#mathematics)
   4. [matriz](#matriz)
   5. [string](#string)
2. [TDA](#tda)
   1. [TDA-date](#tda-date)
   2. [TDA-vector](#tda-vector)
3. [Documentos](#documentos)
4. [Contribución](#contribución)
5. [Licencia](#licencia)


<br/>

## Bibliotecas
El enfoque principal es la reutilización de código mediante:

<b> Manejo de void * </b>: Funciones que operan con cualquier tipo de dato.<br/>
<b> Aritmética de punteros y memoria </b>: Manipulación directa con memcpy y gestión dinámica.<br/>
<b> Punteros a función </b>: Uso de callbacks para comparaciones personalizadas.

### array 

*  arrayInsertElementAtPosition : Inserta un elemento en una posición específica de un arreglo.
*  arrayInsertInSortedOrder : Inserta un elemento en un arreglo ordenado.
*  arrayRemoveElementAtPosition : Elimina un elemento de una posición específica de un arreglo.
*  arrayRemoveFirstOccurrence : Elimina la primera ocurrencia de un elemento en un arreglo.
*  arrayRemoveAllOccurrences : Elimina todas las ocurrencias de un elemento en un arreglo.
* shiftLeftOverwrite : Desplaza los elementos de un arreglo hacia la izquierda, sobreescribiendo el primer elemento.
* shiftRightWithInsert : Desplaza los elementos de un arreglo hacia la derecha, insertando un nuevo elemento en la primera posición.
* averageOfPairs : Calcula el promedio de los pares de elementos de un arreglo.
* arrayPrint: Muestra un arreglo.
* arrayPrintReverse : Muestra un arreglo en orden inverso.
* sumOfAllElements : Calcula la suma de todos los elementos de un arreglo.
* searchMin : Busca el elemento mínimo en un arreglo.
* searchElement : Busca un elemento en un arreglo.
* binarySearch : Busca un elemento en un arreglo ordenado utilizando búsqueda binaria.
* sortInsertion : Ordena un arreglo utilizando el método de inserción.
* sortSelection : Ordena un arreglo utilizando el método de selección.
* swap : Intercambia dos elementos de un arreglo.

### macros
* ROUND : Redondea un número al entero más cercano.
* ABSOLUTE_VALUE : Calcula el valor absoluto de un número.
* INTEGER_PART : Obtiene la parte entera de un número.
* DECIMAL_PART : Obtiene la parte decimal de un número.
* IS_EVEN : Verifica si un número es par.
* IS_LETTER : Verifica si un carácter es una letra.
* IS_DIGIT : Verifica si un carácter es un dígito.
* IS_UPPERCASE : Verifica si un carácter es una letra mayúscula.
* IS_LOWERCASE : Verifica si un carácter es una letra minúscula.
* IS_WHITESPACE : Verifica si un carácter es un espacio en blanco.
* TO_UPPERCASE : Convierte un carácter a mayúsculas.
* TO_LOWERCASE : Convierte un carácter a minúsculas.
* MIN : Calcula el mínimo entre dos números.
* MAX : Calcula el máximo entre dos números.
* IS_POWER_OF : Verifica si un número es una potencia de otro.
* SWAP_VALUES : Intercambia dos valores.


### mathematics

*  power : Calcula la potencia de un número.
*  factorial : Calcula el factorial de un número.
*  binomialCoefficient : Calcula el coeficiente binomial de dos números.
*  ex : Calcula el valor de e^x con una tolerancia dada.
*  absolute : Calcula el valor absoluto de un número.
*  squareRoot : Calcula la raíz cuadrada de un número con una tolerancia dada.
*  isFibonacci : Verifica si un número es un número de Fibonacci.
*  sino : Calcula el seno de un ángulo en radianes con una tolerancia dada.
*  isPerfectNumber : Verifica si un número es un número perfecto.
*  isDeficientNumber : Verifica si un número es un número deficiente.
*  isAbundantNumber : Verifica si un número es un número abundante.
*  multiplyByAddition : Multiplica dos números utilizando sumas sucesivas.
*  divideAndRemainder : Divide dos números y calcula el resto.
*  sumEvenNumbersLessThanN : Calcula la suma de los números pares menores que un número dado.
*  isPrimeNumber : Verifica si un número es un número primo.

### matriz

*  matrixCreate : Crea una matriz dinámica.
*  matrixDestroy : Libera la memoria de una matriz dinámica.
*  matrixShow : Muestra una matriz en la consola.
*  matrixInit : Inicializa una matriz con un valor dado.
*  matrixTrace : Calcula la traza de una matriz cuadrada.
*  sumSecondaryDiagonal : Calcula la suma de los elementos de la diagonal secundaria de una matriz cuadrada.
*  sumAboveMainDiagonal : Calcula la suma de los elementos por encima de la diagonal principal de una matriz cuadrada.
*  sumBelowMainDiagonal : Calcula la suma de los elementos por debajo de la diagonal principal de una matriz cuadrada.
*  sumAboveSecondaryDiagonal : Calcula la suma de los elementos por encima de la diagonal secundaria de una matriz cuadrada.
*  sumBelowSecondaryDiagonal : Calcula la suma de los elementos por debajo de la diagonal secundaria de una matriz cuadrada.
*  isIdentityMatrix : Verifica si una matriz es una matriz identidad.
*  isSymmetricMatrix : Verifica si una matriz es simétrica.
*  sumeMatrix : Suma dos matrices.
*  matrixProduct : Multiplica dos matrices.
*  transposeMatrix : Calcula la transpuesta de una matriz.

### string

* mstrLength : Calcula la longitud de una cadena.
* mstrCat : Concatena dos cadenas.
* mstrnCat : Concatena los primeros n caracteres de una cadena con otra.
* mstrCpy : Copia una cadena en otra.
* mstrnCpy : Copia los primeros n caracteres de una cadena en otra.
* mstrchr : Busca la primera ocurrencia de un carácter en una cadena.
* mstrrchr : Busca la última ocurrencia de un carácter en una cadena.
* mstrCmp : Compara dos cadenas.
* mstrnCmp : Compara los primeros n caracteres de dos cadenas.
* mstrStr : Busca la primera ocurrencia de una subcadena en una cadena.
* mmemmove : Copia una cadena en otra, manejando posibles solapamientos.
* isPalindrome : Verifica si una cadena es un palíndromo.
* stringToInt : Convierte una cadena en un número entero.
* countWordsOccurences : Cuenta las ocurrencias de una palabra en una cadena.
* normalize : Normaliza una cadena.
* searchPosition : Busca la posición de un carácter en una cadena.
* obfuscateStringWithShift : Ofusca una cadena utilizando un desplazamiento de caracteres.


<br/>

## TDA
TDA (Tipos de Datos Abstractos) es una estructura de datos que define un conjunto de operaciones y propiedades que pueden ser aplicadas a un conjunto de valores.

### TDA-date

```c	
typedef struct
{
    int day;
    int month;
    int year;
} Date;
```

* day : Obtiene el día de una fecha.
* month : Obtiene el mes de una fecha.
* year : Obtiene el año de una fecha.
* daysInMonth : Calcula la cantidad de días en un mes de un año dado.
* isLeapYear : Verifica si un año es bisiesto.
* isDateValid : Verifica si una fecha es válida.
* nextDay : Calcula el día siguiente a una fecha dada.
* previousDay : Calcula el día anterior a una fecha dada.
* addDays : Agrega una cantidad de días a una fecha dada.
* subtractDays : Resta una cantidad de días a una fecha dada.
* daysBetweenDates : Calcula la cantidad de días entre dos fechas.
* dayOfWeek : Calcula el día de la semana de una fecha dada.


### TDA-vector

```c
typedef struct
{
    void *array;
    int size;
    size_t sizeElement;
    int capacity;
} Vector;
```

* vectorCreate : Crea un vector.
* vectorResize : Redimensiona un vector.
* vectorDestroy : Libera la memoria de un vector.
* vectorIsFull : Verifica si un vector está lleno.
* vectorIsEmpty : Verifica si un vector está vacío.
* vectorInsertOrdered : Inserta un elemento en un vector ordenado.
* vectorUnshift : Inserta un elemento al inicio de un vector.
* vectorInsertAtPosition : Inserta un elemento en una posición específica de un vector.
* vectorPush : Inserta un elemento al final de un vector.
* vectorShift : Elimina un elemento al inicio de un vector.
* vectorDeleteAtPosition : Elimina un elemento en una posición específica de un vector.
* vectorDeleteElement : Elimina la primera ocurrencia de un elemento en un vector.
* vectorDeleteElementAll : Elimina todas las ocurrencias de un elemento en un vector.
* vectorClear : Elimina todos los elementos de un vector.
* vectorPop : Elimina un elemento al final de un vector.
* vectorSortInsertion : Ordena un vector utilizando el método de inserción.
* vectorSortSelection : Ordena un vector utilizando el método de selección.
* vectorMax : Obtiene el elemento máximo de un vector.
* vectorMin : Obtiene el elemento mínimo de un vector.
* vectorSearch : Busca un elemento en un vector.
* vectorBinarySearch : Busca un elemento en un vector ordenado utilizando búsqueda binaria.
* vectorSwap : Intercambia dos elementos de un vector.
* vectorGet : Obtiene un elemento en una posición específica de un vector.
* vectorGetFirst : Obtiene el primer elemento de un vector.
* vectorGetLast : Obtiene el último elemento de un vector.
* vectorConcat : Concatena dos vectores.
* vectorSet : Establece el valor de un elemento en una posición específica de un vector.
* vectorReverse : Invierte el orden de los elementos de un vector.


<br/>

## Documentos

*  **01-AnciC.pdf** : librerias estandar de C y ejemplos de uso.
*  **IntroduccionC.pdf** : Introduccion a la programacion en C.
*  **Topicos-de-Programacion-(3635)---Ejercicios-propuestos---V2.pdf** : Ejercicios propuestos para la materia.
*  **codigo-ascci.pdf** : Tabla de codigos ASCII.


<br/>
<br/>

## Contribución

Este es un repositorio de carácter personal y académico para la materia **Tópicos de Programación** de la **Universidad Nacional de La Matanza**. Por este motivo, no se aceptan contribuciones externas ni Pull Requests.


<br/>

## Licencia

Este proyecto se distribuye únicamente con fines educativos. <br/>
Todos los derechos reservados © 2024 Matias Corpu.

<br/>

## Contacto

Para cualquier pregunta o sugerencia, puedes contactar a:

*   **Nombre del autor**: Matías Corpu
*   **Correo electrónico**: corpumatiasariel@gmail.com
*   **Perfil de GitHub**: [MatiasCorpu](https://github.com/MatiasCorpu)

