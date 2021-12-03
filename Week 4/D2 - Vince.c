#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define START_POS {0, 0}
#define X_SIZE 10
#define Y_SIZE 10

void initMatrix(char matrix[X_SIZE][Y_SIZE]);
void printMatrix(char matrix[X_SIZE][Y_SIZE]);
void writeMatrix(char matrix[X_SIZE][Y_SIZE], uint8_t pos[2], char* counter);
uint8_t checkPos(char matrix[X_SIZE][Y_SIZE], uint8_t pos[2], char* counter);
uint8_t doStep(char matrix[X_SIZE][Y_SIZE], uint8_t pos[2], char* counter);

int main(void)
{
    srand(time(NULL));

    char matrix[X_SIZE][Y_SIZE];
    initMatrix(matrix);

    char counter = 'A';
    uint8_t pos[] = START_POS;
    writeMatrix(matrix, pos, &counter);

    uint8_t value;
    do
    {
        printMatrix(matrix);
    } while (doStep(matrix, pos, &counter));

    system("PAUSE");
    return 0;
}

void initMatrix(char matrix[X_SIZE][Y_SIZE])
{
    for(int x=0; x<X_SIZE; x++)
        memset(matrix[x], '.', Y_SIZE);
}

void printMatrix(char matrix[X_SIZE][Y_SIZE])
{
    for(int x=0; x<X_SIZE; x++)
    {
        for(int y=0; y<Y_SIZE; y++)
            printf("%c ", matrix[x][y]);
        printf("\n");
    }
    printf("\n");
}

void writeMatrix(char matrix[X_SIZE][Y_SIZE], uint8_t pos[2], char* counter)
{
    matrix[pos[0]][pos[1]] = *counter;
    (*counter)++;
}

uint8_t checkPos(char matrix[X_SIZE][Y_SIZE], uint8_t pos[2], char* counter)
{
    if(pos[0] >= 0 && pos[0] < X_SIZE && pos[1] >= 0 && pos[1] < Y_SIZE)
        return matrix[pos[0]][pos[1]] == '.';
    return 0;
}

uint8_t doStep(char matrix[X_SIZE][Y_SIZE], uint8_t pos[2], char* counter)
{   
    uint8_t bitHack = 0x00;
    uint8_t tempPos[2];
    for(;;)
    {
        memcpy(tempPos, pos, 2);
        int random = rand() % 4 + 1;
        switch(random)
        {
        case 1:
            tempPos[0]--;
            break;
        case 2:
            tempPos[1]++;
            break;
        case 3:
            tempPos[0]++;
            break;
        case 4:
            tempPos[1]--;
            break;
        }
        if(checkPos(matrix, tempPos, counter)) break;
        bitHack |= (1<<random - 1);
        if(bitHack == 0x0F) return 0;
    }
    memcpy(pos, tempPos, 2);
    writeMatrix(matrix, pos, counter);
    return *counter < 92;
}