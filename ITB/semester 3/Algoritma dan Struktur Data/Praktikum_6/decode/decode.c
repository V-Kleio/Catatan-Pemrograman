#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "stack.h"

void decodeString(char* str, char* result) {
    Stack s;
    CreateEmpty(&s);
    int i = 0, j = 0, k, repeat, repeatCounter = -1;
    char temp[10000], ch;
    int repeatArr[10000];

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            // Push the number to the stack
            repeat = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                repeat = repeat * 10 + (str[i] - '0');
                i++;
            }
            repeatCounter++;
            repeatArr[repeatCounter] = repeat;
            //Push(&s, repeat + '0'); // Convert number to char and push
        } else if (str[i] == '[') {
            // Push the '[' to the stack
            Push(&s, '[');
            i++;
        } else if (str[i] == ']') {
            // Pop until '[' and decode the string
            j = 0;
            while (InfoTop(s) != '[') {
                temp[j++] = InfoTop(s);
                Pop(&s, &ch);
            }
            temp[j] = '\0';
            Pop(&s, &ch); // Pop the '['
            repeat = repeatArr[repeatCounter];
            repeatCounter--;
            // repeat = InfoTop(s) - '0'; // Convert char to number
            // Pop(&s, &ch); // Pop the number
            for (k = 0; k < repeat; k++) {
                for (j = strlen(temp) - 1; j >= 0; j--) {
                    Push(&s, temp[j]);
                }
            }
            i++;
        } else {
            // Push the character to the stack
            Push(&s, str[i]);
            i++;
        }
    }

    // Pop all elements to get the result
    j = 0;
    while (!IsEmpty(s)) {
        result[j++] = InfoTop(s);
        Pop(&s, &ch);
    }
    result[j] = '\0';

    // Reverse the result
    for (i = 0, j = strlen(result) - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

int main()
{
    int N;
    char encoded[10001], decoded[10001];

    scanf("%d", &N);
    if (N == 0) {
        printf("\n");
        return 0;
    }
    scanf("%s", encoded);

    decodeString(encoded, decoded);
    printf("%s\n", decoded);

    return 0;
}