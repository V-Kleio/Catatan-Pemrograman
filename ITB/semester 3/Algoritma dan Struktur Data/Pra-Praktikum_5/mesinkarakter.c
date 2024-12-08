#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;

void START() 
{
    ADV();
}

void ADV() 
{
    currentChar = getchar();
    EOP = (currentChar == MARK);
}