#include <stdio.h>
#include <string.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

typedef struct
{
    char *str;
    int value;
} Keyword;

boolean checkCurrentWord(char target[])
{
    int targetLength = 0;
    while (target[targetLength] != '\0')
    {
        targetLength++;
    }

    if (currentWord.Length != targetLength)
    {
        return false;
    }

    for (int i = 0; i < currentWord.Length; i++)
    {
        if (currentWord.TabWord[i] != target[i])
        {
            return false;
        }
    }

    return true;
}

boolean compareStrings(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }
    return str1[i] == str2[i];
}

int stringToNumber(Word string)
{
    int num = -1;
    int base = 0;
    boolean isSpecial = false;
    int specialIdx = -1;

    Keyword keyword[] = {
        {"nol", 0}, {"satu", 1}, {"dua", 2}, {"tiga", 3}, {"empat", 4}, {"lima", 5}, {"enam", 6}, {"tujuh", 7}, {"delapan", 8}, {"sembilan", 9}, {"sepuluh", 10}, {"sebelas", 11}, {"seratus", 100}, {NULL, 0}};

    Keyword special[] = {
        {"belas", 10}, {"puluh", 10}, {"ratus", 100}, {NULL, 0}};

    while (true)
    {
        isSpecial = false;
        specialIdx = -1;
        int tempBase = 0;
        boolean found = false;
        if (checkCurrentWord(keyword[0].str))
        {
            ADVWORD();
            return 0;
        }

        for (int i = 1; keyword[i].str != NULL; i++)
        {
            if (checkCurrentWord(keyword[i].str))
            {
                found = true;
                break;
            }
        }

        for (int i = 1; keyword[i].str != NULL; i++)
        {
            if (checkCurrentWord(keyword[i].str))
            {
                tempBase += keyword[i].value;
                ADVWORD();

                for (int j = 0; special[j].str != NULL; j++)
                {
                    if (checkCurrentWord(special[j].str))
                    {
                        isSpecial = true;
                        specialIdx = j;
                    }
                }
                break;
            }
        }

        if (isSpecial)
        {
            if (compareStrings(special[specialIdx].str, "belas"))
            {
                tempBase += 10;
            }
            else
            {
                tempBase *= special[specialIdx].value;
            }
            base += tempBase;
            ADVWORD();
        }
        else
        {
            base += tempBase;
        }

        if (tempBase == 0 || EndWord)
        {
            break;
        }
    }

    if (base > 0)
    {
        num = base;
    }
    return num;
}

int main()
{
    STARTWORD();

    boolean firstWord = true;

    while (!EndWord)
    {
        if (!firstWord)
        {
            printf(" ");
        }
        int num = stringToNumber(currentWord);
        if (num >= 0)
        {
            printf("%d", num);
        }
        else
        {
            for (int i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }
            ADVWORD();
        }

        firstWord = false;
    }
    printf("\n");
}