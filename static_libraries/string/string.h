#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

#define SIZE_MAX_STRING 100
#define WORD_SIZE 50

#define IS_LETTER(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define TOLOWER(c) (c >= 'A' && c <= 'Z' ? c + 32 : c)
#define TOUPPER(c) (c >= 'a' && c <= 'z' ? c - 32 : c)

typedef struct
{
    char *cursor;
    bool endSequence;
} WordSequence;

typedef struct
{
    char word[WORD_SIZE];
} Word;

// my string library functions
int mstrLength(const char *s);
char *mstrCat(char *s1, const char *s2);
char *mstrnCat(char *s1, const char *s2, size_t n);
char *mstrCpy(char *s1, const char *s2);
char *mstrnCpy(char *s1, const char *s2, size_t n);
char *mstrchr(const char *s, int c);
char *mstrrchr(char *s, int c);
int mstrCmp(const char *s1, const char *s2);
int mstrnCmp(const char *s1, const char *s2, size_t n);
void *mmemmove(void *dest, const void *src, size_t n, size_t sizeElem);

// functions to normalize a string
void createWordSequence(WordSequence *wordSeq, char *string);
bool readWord(WordSequence *wordSeq, Word *word);
void writeWord(WordSequence *wordSeq, const Word *word);
void writeCharacter(WordSequence *wordSeq, const char character);
void capitalizeWord(Word *word);
bool endOfWordSequence(const WordSequence *wordSeq);
void repositionCursor(WordSequence *wordSeq, int displacement);
void closeWordSequence(WordSequence *wordSeq);
char *normalize(const char *stringToNormalize, char *normalizedString);

// functions to obfuscate and deobfuscate a string
int searchPosition(const char *string, const char c);
void deobfuscateWord(Word *word, const char *key);
char *obfuscateStringWithShift(const char *obfuscated, char *deobfuscated, const char *key);

// other functions
bool isPalindrome(const char *s);
int stringToInt(const char *s);
int countWordsOccurences(const char *string, const char *word);

#endif // STRING_H_INCLUDED