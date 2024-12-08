#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main()
{
    int N, i;
    char ch;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        char temp;
        if (!IsEmpty(s))
        {
            if (InfoTop(s) == '(' && ch == ')')
            {
                Pop(&s, &temp);
            }
            else if (InfoTop(s) == '[' && ch == ']')
            {
                Pop(&s, &temp);
            }
            else if (InfoTop(s) == '{' && ch == '}')
            {
                Pop(&s, &temp);
            }
            else
            {
                Push(&s, ch);
            }
        }
        else
        {
            Push(&s, ch);
        }
    }
    

    if (IsEmpty(s))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
    

    return 0;
}