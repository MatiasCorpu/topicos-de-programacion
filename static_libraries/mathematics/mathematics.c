#include "mathematics.h"

int power(int base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}

int factorial(int n)
{
    int result = 1;
    while (n > 1)
    {
        result *= n;
        n--;
    }
    return result;
}

int binomialCoefficient(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

float ex(int x, float tol)
{
    float result = 1;
    float term = 1;
    int i = 1;
    while (term > tol)
    {
        term = term * x / i;
        result += term;
        i++;
    }
    return result;
}

int absolute(int x)
{
    return x > 0 ? x : x * -1;
}

float squareRoot(float x, float tol)
{
    float result = x / 2;
    float difference = result * result - x;
    while (difference > tol || difference < -tol)
    {
        result = (result + x / result) / 2;
        difference = result * result - x;
    }

    return result;
}

bool isFibonacci(int n)
{
    int term1 = 1;
    int term2 = 1;
    int aux;

    while (term2 < n)
    {
        aux = term2;
        term2 = term1 + term2;
        term1 = aux;
    }
    return term2 == n;
}

float seno(float x, float tol)
{
    float result = x;
    float term = x;
    int i = 1;
    while (term > tol || term < -tol)
    {
        term = -term * x * x / ((i + 1) * (i + 2));
        result += term;
        i += 2;
    }
    return result;
}

bool isPerfectNumber(int n)
{
    int num = 2;
    int result = 1;

    while (num < n)
    {
        if (n % num == 0)
            result += num;
        num++;
    }
    return result == n;
}

bool isDeficientNumber(int n)
{
    int num = 2;
    int result = 1;

    while (num < n)
    {
        if (n % num == 0)
            result += num;
        num++;
    }
    return result < n;
}

bool isAbundantNumber(int n)
{
    int num = 2;
    int result = 1;

    while (num < n)
    {
        if (n % num == 0)
            result += num;
        num++;
    }
    return result > n;
}

int multiplyByAddition(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;

    return result;
}

int divideAndRemainder(int a, int b, int *remainder)
{
    int result = 0;
    while (a >= b)
    {
        a -= b;
        result++;
    }
    if (remainder != NULL)
        *remainder = a;
    return result;
}

int sumEvenNumbersLessThanN(int n)
{
    int result = 0;
    for (int i = 2; i < n; i += 2)
        result += i;

    return result;
}

int isPrimeNumber(int n)
{
    int result = 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            result++;
    return result == 0;
}
