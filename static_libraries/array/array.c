#include "array.h"

void shiftLeftOverwrite(void *current, void *last, size_t sizeElem)
{
    for (void *i = current; i <= last; i += sizeElem)
        memcpy(i, i + sizeElem, sizeElem);
}

void shiftRightWithInsert(void *current, void *last, size_t sizeElem)
{
    for (void *i = last; i >= current; i -= sizeElem)
        memcpy(i + sizeElem, i, sizeElem);
}

void arrayRemoveAllOccurrences(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp)
{
    void *current = arr;
    void *last = arr + (*ce - 1) * sizeElem;

    while (current <= last)
    {
        if (cmp(current, elem) == 0)
        {
            shiftLeftOverwrite(current, last, sizeElem);
            (*ce)--;
            last -= sizeElem;
        }
        else
            current += sizeElem;
    }
}

void arrayRemoveFirstOccurrence(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp)
{
    void *last = arr + sizeElem * (*ce - 1);

    while (arr <= last)
    {
        if (cmp(arr, elem) == 0)
            break;

        arr += sizeElem;
    }

    shiftLeftOverwrite(arr, last, sizeElem);

    (*ce)--;
}

void arrayRemoveElementAtPosition(void *arr, int *ce, size_t sizeElem, int pos)
{
    void *current = arr + (pos - 1) * sizeElem;
    void *last = arr + (*ce - 1) * sizeElem;

    shiftLeftOverwrite(current, last, sizeElem);

    (*ce)--;
}

void arrayInsertElementAtPosition(void *arr, int *ce, size_t sizeElem, int cap, void *elem, int pos)
{
    void *current = arr + (pos - 1) * sizeElem;
    void *last = arr + (*ce - 1) * sizeElem;

    shiftRightWithInsert(current, last, sizeElem);

    memcpy(current, elem, sizeElem);

    (*ce)++;
}

int arrayInsertInSortedOrder(void *arr, int *ce, size_t sizeElem, int cap, void *elem, Compare cmp)
{
    if (cap == *ce)
        return ERR_MEM;

    void *curr = arr;
    void *last = arr + sizeElem * (*ce - 1);

    int comp;

    while (curr <= last)
    {
        comp = cmp(elem, curr);

        if (comp < 0)
            break;

        else if (comp == 0)
            return DUPLICATE;

        curr += sizeElem;
    }

    for (void *i = last; i >= curr; i -= sizeElem)
        memcpy(i + sizeElem, i, sizeElem);

    (*ce)++;
    memcpy(curr, elem, sizeElem);

    return ALL_OK;
}

void arrayPrint(void *arr, int ce, size_t sizeElem, Show show)
{
    void *last = arr + sizeElem * (ce - 1);

    for (void *i = arr; i <= last; i += sizeElem)
        show(i);
}

//-----------------------------------------------
double averageOfPairs(void *arr, int ce, size_t sizeElem)
{
    double r = 0.0;
    int n = 0;

    for (void *i = arr; i < arr + ce * sizeElem; i += (sizeElem * 2))
    {
        r += *(int *)i;
        n++;
    }

    return r / n;
}

void arrayPrintReverse(void *arr, int ce, size_t sizeElem, Show show)
{
    void *last = arr + (ce - 1) * sizeElem;

    for (void *i = last; i >= arr; i -= sizeElem)
        show(i);
}

void *searchMin(void *arr, int ce, size_t sizeElem, Compare cmp)
{
    void *ptr = arr;
    void *last = arr + (ce - 1) * sizeElem;

    while (arr <= last)
    {
        if (cmp(ptr, arr) > 0)
            ptr = arr;

        arr += sizeElem;
    }

    return ptr;
}

void *searchElement(void *arr, int ce, size_t sizeElem, void *elem, Compare cmp)
{
    void *last = arr + (ce - 1) * sizeElem;

    for (void *i = arr; i <= last; i += sizeElem)
        if (cmp(i, elem) == 0)
            return i;

    return NULL;
}

void *binarySearch(void *arr, int ce, size_t sizeElem, void *elem, Compare cmp)
{
    void *first = arr;
    void *last = arr + (ce - 1) * sizeElem;
    void *mid;

    while (first <= last)
    {
        mid = first + ((last - first) / (2 * sizeElem)) * sizeElem;

        if (cmp(mid, elem) == 0)
            return mid;

        if (cmp(mid, elem) < 0)
            first = mid + sizeElem;
        else
            last = mid - sizeElem;
    }

    return NULL;
}

void sortInsertion(void *arr, int ce, size_t sizeElem, Compare cmp)
{
    void *toInsert = malloc(sizeElem);
    if (toInsert == NULL)
        return;

    void *last = arr + (ce - 1) * sizeElem;
    void *j;

    for (void *i = arr + sizeElem; i <= last; i += sizeElem)
    {
        memcpy(toInsert, i, sizeElem);

        for (j = i - sizeElem; j >= arr && cmp(toInsert, j) < 0; j -= sizeElem)
            memcpy(j + sizeElem, j, sizeElem);

        memcpy(j + sizeElem, toInsert, sizeElem);
    }

    free(toInsert);
}

void swap(void *a, void *b, size_t sizeElem)
{
    void *aux = malloc(sizeElem);
    if (aux == NULL)
        return;

    memcpy(aux, a, sizeElem);
    memcpy(a, b, sizeElem);
    memcpy(b, aux, sizeElem);
    free(aux);
}

void sortSelection(void *arr, int ce, size_t sizeElem, Compare cmp)
{
    void *ptr;
    void *last = arr + (ce - 1) * sizeElem;

    for (void *i = arr; i < last; i += sizeElem)
    {
        ptr = searchMin(i, ce--, sizeElem, cmp);

        if (cmp(i, ptr) != 0)
            swap(i, ptr, sizeElem);
    }
}

// esto no tendria que ir no es parte de la libreria array:
int cmpInst(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

void showInt(void *x)
{
    printf("%d ", *(int *)x);
}
