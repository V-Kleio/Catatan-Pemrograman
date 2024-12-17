#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char letter;
    int value;
} alphabet;

const alphabet lowercase[] =
{
    {'a', 1},
    {'b', 2},
    {'c', 3},
    {'d', 4},
    {'e', 5},
    {'f', 6},
    {'g', 7},
    {'h', 8},
    {'i', 9},
    {'j', 10},
    {'k', 11},
    {'l', 12},
    {'m', 13},
    {'n', 14},
    {'o', 15},
    {'p', 16},
    {'q', 17},
    {'r', 18},
    {'s', 19},
    {'t', 20},
    {'u', 21},
    {'v', 22},
    {'w', 23},
    {'x', 24},
    {'y', 25},
    {'z', 26},
};

const alphabet uppercase[] =
{
    {'A', 1},
    {'B', 2},
    {'C', 3},
    {'D', 4},
    {'E', 5},
    {'F', 6},
    {'G', 7},
    {'H', 8},
    {'I', 9},
    {'J', 10},
    {'K', 11},
    {'L', 12},
    {'M', 13},
    {'N', 14},
    {'O', 15},
    {'P', 16},
    {'Q', 17},
    {'R', 18},
    {'S', 19},
    {'T', 20},
    {'U', 21},
    {'V', 22},
    {'W', 23},
    {'X', 24},
    {'Y', 25},
    {'Z', 26},
};

void printDecryptedCurrentWord(int key);

int main()
{
    int key;

    scanf("%i", &key);
    STARTWORD();
    printDecryptedCurrentWord(key);
    ADVWORD();
    while (!EndWord)
    {
        printf(" ");
        printDecryptedCurrentWord(key);
        ADVWORD();
    }
    printf("\n");
    return 0;
}

void printDecryptedCurrentWord(int key)
{
    int i, j, originalValue, decryptedValue;

    for (i = 0; i < currentWord.Length; i++)
    {
        if (currentWord.TabWord[i] >= 97 && currentWord.TabWord[i] <= 122)
        {
            for (j = 0; j < 26; j++)
            {
                if (currentWord.TabWord[i] == lowercase[j].letter)
                {
                    originalValue = lowercase[j].value;
                    decryptedValue = originalValue - (key % 26);
                    if (decryptedValue < 1)
                    {
                        decryptedValue = 26 + decryptedValue;
                    }
                    printf("%c", lowercase[decryptedValue - 1].letter);
                }
            }
        }
        else if (currentWord.TabWord[i] >= 65 && currentWord.TabWord[i] <= 90)
        {
            for (j = 0; j < 26; j++)
            {
                if (currentWord.TabWord[i] == uppercase[j].letter)
                {
                    originalValue = uppercase[j].value;
                    decryptedValue = originalValue - (key % 26);
                    if (decryptedValue < 1)
                    {
                        decryptedValue = 26 + decryptedValue;
                    }
                    printf("%c", uppercase[decryptedValue - 1].letter);
                }
            }
        }
        else
        {
            printf("%c", currentWord.TabWord[i]);
        }
    }
}