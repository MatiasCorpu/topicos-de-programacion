#ifndef MATHEMATICS_H_INCLUDED
#define MATHEMATICS_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>

int power(int base, int exponent);
int factorial(int n);
int binomialCoefficient(int n, int k);
float ex(int x, float tol);
int absolute(int x);
float squareRoot(float x, float tol); //<-- This function is not working properly
bool isFibonacci(int n);
float seno(float x, float tol); //<-- This function is not working properly
bool isPerfectNumber(int n);
bool isDeficientNumber(int n);
bool isAbundantNumber(int n);
int multiplyByAddition(int a, int b);
int divideAndRemainder(int a, int b, int *remainder);
int sumEvenNumbersLessThanN(int n);
int isPrimeNumber(int n);


#endif // MATHEMATICS_H_INCLUDED
