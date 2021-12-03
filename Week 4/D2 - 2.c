#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum direction { // so up, etc can be used in functions, compile time constants
    up = -10,
    left = -1,
    down = 10,
    right = 1
};

int is_valid_dir(char *array, int index, int dir) {
    switch (dir) {
        case up:
            return (index > 10 && *(array + index + dir) == '.');  // if pos isnt topmost, and above is .
        case left:
            return (index % 10 && *(array + index + dir) == '.'); // if pos isn't leftmost, and left isn't "."
        case down:
            return (index < 90 && *(array + index + 10) == '.'); //if pos isn't downmost, and down isn't "."
        case right:
            return (index % 10 != 9 && *(array + index + dir) == '.');
        default:
            return false;
    }
}

int is_stuck(char *arr, int index) {
    return !(is_valid_dir(arr, index, up) ||
            is_valid_dir(arr, index, down) ||
            is_valid_dir(arr, index, left) ||
            is_valid_dir(arr, index, right)
    );
}

int main() {
    srand(time(0)); // seed rand
    int direction[4] = {-10, -1, 10, 1}; // to convert rand output to a position change
    // generate maze
    char maze[10][10] = {};
    for (int i = 0; i < 10; i++) { // the 2d way
        for (int j = 0; j < 10; j++) {
            maze[i][j] = '.';
        }
    }
    char character = 'A';
    int pos = 0;
    maze[0][0] = character;
    // traverse maze
    for (int i = 0; i < 25; i++) {
        int dir = direction[rand() % 4];
        while (!is_valid_dir(maze, pos, dir) && !is_stuck(maze, pos)) {
            dir = direction[rand() % 4];
        }
        if (is_stuck(maze, pos)) {
            printf("Got myself in a sticky situation\n");
            break;
        }
        pos += dir;
        maze[pos / 10][pos % 10] = ++character;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

}