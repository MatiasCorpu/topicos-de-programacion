#include "string.h"

int mstrLength(const char *s)
{
    int length = 0;
    while (*s != '\0')
    {
        length++;
        s++;
    }
    return length;
}

char *mstrCat(char *s1, const char *s2)
{
    char *start = s1;
    while (*s1 != '\0')
        s1++;

    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';

    return start;
}

char *mstrnCat(char *s1, const char *s2, size_t n)
{
    char *start = s1;
    while (*s1 != '\0')
        s1++;

    while (*s2 != '\0' && n > 0)
    {
        *s1 = *s2;
        s1++;
        s2++;
        n--;
    }

    *s1 = '\0';

    return start;
}

char *mstrCpy(char *s1, const char *s2)
{
    char *start = s1;

    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return start;
}

char *mstrnCpy(char *s1, const char *s2, size_t n)
{
    char *start = s1;

    while (*s2 != '\0' && n > 0)
    {
        *s1 = *s2;
        s1++;
        s2++;
        n--;
    }

    *s1 = '\0';

    return start;
}

char *mstrchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    return NULL;
}

char *mstrrchr(char *s, int c)
{
    char *last = NULL;
    while (*s != '\0')
    {
        if (*s == c)
            last = (char *)s;
        s++;
    }
    return last;
}

int mstrCmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        int dif = (*s1 - *s2);
        if (dif != 0)
            return dif;
        s1++;
        s2++;
    }

    return *s1 != '\0' ? 1 : *s2 != '\0' ? -1
                                         : 0;
}

int mstrnCmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 != '\0' && *s2 != '\0' && n > 0)
    {
        int dif = *s1 - *s2;
        if (dif != 0)
            return dif;
        s1++;
        s2++;
        n--;
    }

    return n == 0 ? 0 : *s1 != '\0' ? 1
                    : *s2 != '\0'   ? -1
                                    : 0;
}

void *mmemmove(void *dest, const void *src, size_t n, size_t sizeElem)
{
    void *temp = malloc(n * sizeElem);
    if(temp == NULL)
        return NULL;

    for(int i = 0; i < n; i++)
    {
        memcpy(temp + (i * sizeElem), src + (i * sizeElem), sizeElem);
    }

    memcpy(dest, temp, sizeElem * n);

    free(temp);
}

//............................................................

bool isPalindrome(const char *s)
{
    const char *left = s;
    const char *right = s + mstrLength(s) - 1;

    while (left < right)
    {
        while (left < right && !IS_LETTER(*left))
            left++;

        while (left < right && !IS_LETTER(*right))
            right--;

        if (TOLOWER(*left) != TOLOWER(*right))
            return false;

        left++;
        right--;
    }

    return true;
}

int stringToInt(const char *s)
{
    int result = 0;
    int multiplier = 1;
    const char *last = s + mstrLength(s) - 1;

    while (s <= last)
    {
        result += (*last - '0') * multiplier;
        multiplier *= 10;
        last--;
    }
    return result;
}

//............................................................
void createWordSequence(WordSequence *wordSeq, char *string)
{
    wordSeq->cursor = string;
    wordSeq->endSequence = false;
}

bool endOfWordSequence(const WordSequence *wordSeq)
{
    return wordSeq->endSequence;
}

bool readWord(WordSequence *wordSeq, Word *word)
{
    while (*wordSeq->cursor != '\0' && !IS_LETTER(*wordSeq->cursor))
        wordSeq->cursor++;

    if (*wordSeq->cursor == '\0')
    {
        wordSeq->endSequence = true;
        return false;
    }

    char *currWord = word->word;

    while (*wordSeq->cursor != '\0' && IS_LETTER(*wordSeq->cursor))
    {
        *currWord = *wordSeq->cursor;
        currWord++;
        wordSeq->cursor++;
    }

    *currWord = '\0';
    return true;
}

void capitalizeWord(Word *word)
{
    char *curr = word->word;

    *curr = TOUPPER(*curr);
    curr++;

    while (*curr != '\0')
    {
        *curr = TOLOWER(*curr);
        curr++;
    }
}

void writeWord(WordSequence *wordSeq, const Word *word)
{
    const char *curr = word->word;

    while (*curr != '\0')
    {
        *wordSeq->cursor = *curr;
        curr++;
        wordSeq->cursor++;
    }
}

void writeCharacter(WordSequence *wordSeq, const char character)
{
    *wordSeq->cursor = character;
    wordSeq->cursor++;
}

void repositionCursor(WordSequence *wordSeq, int displacement)
{
    wordSeq->cursor += displacement;
}

void closeWordSequence(WordSequence *wordSeq)
{
    *wordSeq->cursor = '\0';
}

char *normalize(const char *stringToNormalize, char *normalizedString)
{
    WordSequence readSeq;
    createWordSequence(&readSeq, (char *)stringToNormalize);

    WordSequence writeSeq;
    createWordSequence(&writeSeq, normalizedString);

    Word word;

    readWord(&readSeq, &word);
    while (!endOfWordSequence(&readSeq))
    {
        capitalizeWord(&word);
        writeWord(&writeSeq, &word);
        writeCharacter(&writeSeq, ' ');
        readWord(&readSeq, &word);
    }

    repositionCursor(&writeSeq, -1);
    closeWordSequence(&writeSeq);

    return normalizedString;
}

int searchPosition(const char *string, const char c)
{
    int pos = 0;
    while (*string != '\0')
    {
        if (*string == c)
            return pos;
        pos++;
        string++;
    }
    return -1;
}

void deobfuscateWord(Word *word, const char *key)
{
    int pos = 0;
    int count = 1;
    int len = mstrLength(key);

    char *curr = word->word;

    while (*curr != '\0')
    {
        pos = searchPosition(key, *curr);
        if (pos != -1)
            *curr = *(key + (pos + count) % len);

        count++;
        curr++;
    }
}

char *obfuscateStringWithShift(const char *obfuscated, char *deobfuscated, const char *key)
{
    WordSequence readSeq;
    createWordSequence(&readSeq, (char *)obfuscated);

    WordSequence writeSeq;
    createWordSequence(&writeSeq, (char *)deobfuscated);

    Word word;

    readWord(&readSeq, &word);
    while (!endOfWordSequence(&readSeq))
    {
        deobfuscateWord(&word, key);
        writeWord(&writeSeq, &word);
        writeCharacter(&writeSeq, ' ');
        readWord(&readSeq, &word);
    }

    repositionCursor(&writeSeq, -1);
    closeWordSequence(&writeSeq);

    return deobfuscated;
}

int countWordsOccurences(const char *string, const char *word)
{
    int count = 0;

    WordSequence readSeq;
    createWordSequence(&readSeq, (char *)string);

    Word wordRead;

    readWord(&readSeq, &wordRead);
    while (!endOfWordSequence(&readSeq))
    {
        if (mstrCmp(wordRead.word, word) == 0)
            count++;
        readWord(&readSeq, &wordRead);
    }

    return count;
}