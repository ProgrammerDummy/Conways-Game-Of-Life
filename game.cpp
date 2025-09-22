/*

rules:

1) Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2) Any live cell with two or three live neighbours lives on to the next generation.
3) Any live cell with more than three live neighbours dies, as if by overpopulation.
4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

--> neighbors of a cell are the eight cells surrounding the cells (adjacently and diagonally)
*/

#include <iostream>
#include <vector>
#include <pybind11/pybind.h>
#include <pybind11/stl.h>

#define GRID_SIZE 8

std::vector<std::vector<int>> grid(GRID_SIZE, std::vector<int>(GRID_SIZE, 0));

std::vector<std::vector<int>> dummygrid(GRID_SIZE, std::vector<int>(GRID_SIZE, 0));

bool naiveCheck(int x, int y) {
    int count = 0;

    for(int i  = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            if(x+i >= 0 && x+i <= GRID_SIZE-1 && y+i >= 0 && y+i <= GRID_SIZE-1) {
                if(x != 0 || y != 0) {
                    if(grid[i][j] == 1) {
                        count++;
                    }
                }
            }
        }
    }

    if(count < 2) {
        return 0;
    }

    if(count > 3) {
        return 0;
    }

    return 1;
}

void dummytoreal(void) {
    for(int y = 0; y < GRID_SIZE; y++) {
        for(int x = 0; x < GRID_SIZE; x++) {
            if(naiveCheck(x, y)) {
                dummygrid[y][x] = 1;
            }

            else {
                dummygrid[y][x] = 0;
            }
        }
    }

    for(int y = 0; y < GRID_SIZE; y++) {
        for(int x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = dummygrid[y][x];
        }
    }
}

void adding(int a, int b) {
    return a+b;
}