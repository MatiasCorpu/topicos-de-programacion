#include "tda-vector.h"

void *vectorCreate(Vector *v, int cap, size_t sizeElement)
{
    v->array = malloc(cap * sizeElement);
    if (v->array == NULL)
        return NULL;

    v->size = 0;
    v->sizeElement = sizeElement;
    v->capacity = cap;
    return v->array;
}

bool vectorResize(Vector *v)
{
    void *tmp = realloc(v->array, v->capacity * 2 * v->sizeElement);
    if (tmp == NULL)
        return false;

    v->array = tmp;
    v->capacity *= 2;
    return true;
}

void vectorDestroy(Vector *v)
{
    free(v->array);
    v->array = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool vectorIsFull(Vector *v)
{
    return v->capacity == v->size;
}

bool vectorIsEmpty(Vector *v)
{
    return v->size == 0;
}

int vectorInsertOrdered(Vector *v, void *data, Compare cmp)
{
    if (vectorIsFull(v))
        vectorResize(v);

    void *l = v->array;
    void *r = v->array + (v->size - 1) * v->sizeElement;
    void *mid;

    while (l <= r)
    {
        mid = l + (r - l) / (2 * v->sizeElement) * v->sizeElement;

        if (cmp(mid, data) == 0)
            return DUPLICATE;
        else if (cmp(mid, data) < 0)
            l = mid + v->sizeElement;
        else
            r = mid - v->sizeElement;
    }

    vectorUnshift(v, data, l);

    return OK;
}

void vectorInsertAtPosition(Vector *v, void *data, int pos)
{
    vectorUnshift(v, data, v->array + pos * v->sizeElement);
}

void vectorUnshift(Vector *v, void *data, void *pos)
{
    if (vectorIsFull(v))
        vectorResize(v);

    if (pos == NULL)
        pos = v->array;

    for (void *i = v->array + v->size * v->sizeElement; i > pos; i -= v->sizeElement)
        memcpy(i, i - v->sizeElement, v->sizeElement);

    memcpy(pos, data, v->sizeElement);

    v->size++;
}

void vectorPush(Vector *v, void *data)
{
    if (vectorIsFull(v))
        vectorResize(v);

    memcpy(v->array + v->size * v->sizeElement, data, v->sizeElement);
    v->size++;
}

void vectorPop(Vector *v)
{
    v->size--;
}

void vectorShift(Vector *v, void *pos)
{
    if (pos == NULL)
        pos = v->array;

    for (void *i = pos; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
        memcpy(i, i + v->sizeElement, v->sizeElement);

    v->size--;
}

void vectorDeleteAtPosition(Vector *v, int pos)
{
    vectorShift(v, v->array + pos * v->sizeElement);
}

void vectorDeleteElement(Vector *v, void *data, Compare cmp)
{
    for (void *i = v->array; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
    {
        if (cmp(i, data) == 0)
        {
            vectorShift(v, i);
            return;
        }
    }
}

void vectorDeleteElementAll(Vector *v, void *data, Compare cmp)
{
    for (void *i = v->array; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
    {
        if (cmp(i, data) == 0)
        {
            vectorShift(v, i);
            i -= v->sizeElement;
        }
    }
}

void vectorClear(Vector *v)
{
    v->size = 0;
}

void vectorSortInsertion(Vector *v, Compare cmp)
{
    void *elemInsert = malloc(v->sizeElement);
    void *j;

    for (void *i = v->array + v->sizeElement; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
    {
        memcpy(elemInsert, i, v->sizeElement);

        for (j = i - v->sizeElement; j >= v->array && cmp(elemInsert, j) < 0; j -= v->sizeElement)
            memcpy(j + v->sizeElement, j, v->sizeElement);

        memcpy(j + v->sizeElement, elemInsert, v->sizeElement);
    }

    free(elemInsert);
}

void vectorSortSelection(Vector *v, Compare cmp)
{
    void *min;
    void *last = v->array + (v->size - 1) * v->sizeElement;

    for (void *i = v->array; i < last; i += v->sizeElement)
    {
        min = vectorMin(v, cmp, i);

        if (cmp(min, i) != 0)
            vectorSwap(v, (i - v->array) / v->sizeElement, (min - v->array) / v->sizeElement);
    }
}

void *vectorMax(Vector *v, Compare cmp, void *iniPos)
{
    if (iniPos == NULL)
        iniPos = v->array;

    void *max = iniPos;

    for (void *i = iniPos + v->sizeElement; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
    {
        if (cmp(i, max) > 0)
            max = i;
    }

    return max;
}

void *vectorMin(Vector *v, Compare cmp, void *iniPos)
{
    if (iniPos == NULL)
        iniPos = v->array;

    void *min = iniPos;

    for (void *i = iniPos + v->sizeElement; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
    {
        if (cmp(i, min) < 0)
            min = i;
    }

    return min;
}

void *vectorSearch(Vector *v, void *data, Compare cmp)
{
    void *i;

    for (i = v->array; i < v->array + v->size * v->sizeElement; i += v->sizeElement)
    {
        if (cmp(i, data) == 0)
            return i;
    }

    return NULL;
}

void *vectorBinarySearch(Vector *v, void *data, Compare cmp)
{
    void *first = v->array;
    void *last = v->array + (v->size - 1) * v->sizeElement;
    void *mid;

    while (first <= last)
    {
        mid = first + ((last - first) / (2 * v->sizeElement)) * v->sizeElement;

        printf("mid: %d\n", *(int *)mid);

        if (cmp(mid, data) == 0)
            return mid;

        if (cmp(mid, data) < 0)
            first = mid + v->sizeElement;
        else
            last = mid - v->sizeElement;
    }

    return NULL;
}

void vectorSwap(Vector *v, int pos1, int pos2)
{
    void *tmp = malloc(v->sizeElement);
    void *elem1 = v->array + pos1 * v->sizeElement;
    void *elem2 = v->array + pos2 * v->sizeElement;

    memcpy(tmp, elem1, v->sizeElement);
    memcpy(elem1, elem2, v->sizeElement);
    memcpy(elem2, tmp, v->sizeElement);

    free(tmp);
}