#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define GRID_SIZE 3
#define TREASURE_COUNT 6
#define MIN_TREASURE_COUNT 5
#define MAX_MOVES 10

int treasuresFound = 0;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for ( j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '_';
        }
    }
}

void placeTreasures(char grid[GRID_SIZE][GRID_SIZE]) {
    int test_code_as_seed;
    //printf("\nEnter the test code 2024: ");
    //scanf(" %d", &test_code_as_seed);
    //srand(time(0));
    
    int placed = 0;
    while (placed < TREASURE_COUNT) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '_') {
            grid[x][y] = 'T';
            placed++;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], int playerX, int playerY) {
    int i, j;
    //printf("Treasures Found = %d\n",treasuresFound);
	printf("\n");
    for ( i = 0; i < GRID_SIZE; i++) {
        for ( j = 0; j < GRID_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            } else if (grid[i][j] == 'T') {
                printf("T ");
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerX = 0, playerY = 0,  moves = 0;
    char move;
	
	srand(2024);
	
		initializeGrid(grid);
		placeTreasures(grid);
		playerX = rand() % GRID_SIZE;
		playerY = rand() % GRID_SIZE;

		while (treasuresFound < TREASURE_COUNT && moves < MAX_MOVES) {
			printGrid(grid, playerX, playerY);
			printf("\nmoves = %d Treasures Found = %d\n",moves, treasuresFound);
			printf("\nEnter move (D/L/U/R): ");
			scanf(" %c", &move);

			if (move == 'U' && playerX > 0) playerX--;
			else if (move == 'D' && playerX < GRID_SIZE - 1) playerX++;
			else if (move == 'L' && playerY > 0) playerY--;
			else if (move == 'R' && playerY < GRID_SIZE - 1) playerY++;

			if (grid[playerX][playerY] == 'T') {
				treasuresFound++;
				grid[playerX][playerY] = '_'; // Remove the treasure
			}
			
			moves++;
			
		}

		if (treasuresFound >= TREASURE_COUNT) {
			printf("\nCongratulations! You found all the treasures in %d.\n", moves-1);
		} else {
			printf("\nSorry, you ran out of moves. You used %d moves\n", moves-1);
		}

		return 0;
	} 


