#include <stdio.h>
#include "boolean.h"
#include "stack.h"

// HINT: Gunakan (c - '0') untuk mengubah character ke angka

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

        if (ch == '+')
        {
            int temp1;
            Pop(&s, &temp1);
            int sum = temp1 + InfoTop(s);
            Push(&s, temp1);
            Push(&s, sum);    
        }
        else if (ch == 'X')
        {
            int temp;
            Pop(&s, &temp);
        }
        else if (ch == 'S')
        {
            int temp, sum = 0;
            while (!IsEmpty(s))
            {
                Pop(&s, &temp);
                sum += temp;
            }
            Push(&s, sum);
        }
        else if (ch == 'A')
        {
            int temp, counter = 0, sum = 0, avg = 0;
            while (!IsEmpty(s))
            {
                Pop(&s, &temp);
                sum += temp;
                counter += 1;
            }
            if (counter != 0)
            {
                avg = sum / counter;
            }
            Push(&s, avg);
        }
        else
        {
            Push(&s, ch - '0');
        }
    }

    int sum = 0;
    int temp;
    while (!IsEmpty(s))
    {
        Pop(&s, &temp);
        sum += temp;
    }
    printf("%i\n", sum);

    return 0;
}


