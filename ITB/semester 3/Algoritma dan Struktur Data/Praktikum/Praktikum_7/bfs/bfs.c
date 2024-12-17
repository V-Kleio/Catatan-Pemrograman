#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;

int main() {
    int N;
    int directionX[] = {0, 0, -1, 1};
    int directionY[] = {-1, 1, 0, 0};
    char grid[MXN][MXN];
    int startXPosition, startYPosition, targetXPosition, targetYPosition;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'A') 
            {
                startXPosition = i;
                startYPosition = j;
            } 
            else if (grid[i][j] == 'B') 
            {
                targetXPosition = i;
                targetYPosition = j;
            }
        }
    }


    Queue bfsQueue;
    CreateQueue(&bfsQueue);
    boolean visited[MXN][MXN];
    int distance[MXN][MXN];

    for (int i = 0; i < MXN; i++) 
    {
        for (int j = 0; j < MXN; j++) 
        {
            visited[i][j] = false;
            distance[i][j] = 0;
        }
    }

    ElType initialPosition = {startXPosition, startYPosition};
    enqueue(&bfsQueue, initialPosition);
    visited[startXPosition][startYPosition] = true;

    int found = 0;
    int result = -1;

    while (!isEmpty(bfsQueue)) 
    {
        ElType frontElement;
        dequeue(&bfsQueue, &frontElement);

        int x = frontElement.row;
        int y = frontElement.col;

        if (x == targetXPosition && y == targetYPosition) 
        {
            found = 1;
            result = distance[x][y];
            break;
        }

        for (int i = 0; i < 4; i++) 
        {
            int newXPosition = x + directionX[i];
            int newYPosition = y + directionY[i];

            if (newXPosition >= 0 && newXPosition < N && newYPosition >= 0 && newYPosition < N && !visited[newXPosition][newYPosition] && grid[newXPosition][newYPosition] != '#') 
            {
                ElType nextPosition = {newXPosition, newYPosition};
                enqueue(&bfsQueue, nextPosition);
                visited[newXPosition][newYPosition] = true;
                distance[newXPosition][newYPosition] = distance[x][y] + 1;
            }
        }
    }

    if (found) 
    {
        printf("Ya\n%d\n", result);
    } 
    else 
    {
        printf("Tidak\n");
    }

    return 0;
}