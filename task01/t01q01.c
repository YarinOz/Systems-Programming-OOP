#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 3
#define TREASURE_COUNT 6
#define MAX_MOVES 10

void grid_init(char grid[GRID_SIZE][GRID_SIZE]){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            grid[i][j] = '_';
        }
    }
}

void treasure_init(char grid[GRID_SIZE][GRID_SIZE]){
    int treasuresPlaced = 0;
    while (treasuresPlaced < TREASURE_COUNT){
        int randrow = rand() % GRID_SIZE;
        int randcol = rand() % GRID_SIZE;
        if (grid[randrow][randcol] == '_'){
            grid[randrow][randcol] = 'T';
            treasuresPlaced++;
        }
    }
}

void Player_init(int* playerrow, int* playercol){ 
    *playerrow = rand() % GRID_SIZE;
    *playercol = rand() % GRID_SIZE;
}

void print_turn(char grid[GRID_SIZE][GRID_SIZE], int* playerrow, int* playercol, int* moves, int* treasuresFound){
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                if (i == *playerrow && j == *playercol)
                    printf("P ");
                else
                    printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
    printf("\nmoves = %d Treasures Found = %d\n\n", *moves, *treasuresFound);
    printf("Enter move (D/L/U/R):\n");
}

void turn(char grid[GRID_SIZE][GRID_SIZE], int* playerrow, int* playercol, int* moves, int* treasuresFound){
    char move[3];     // buffer size [char, \n, \0] flags
    fgets(move, sizeof(move), stdin); // Scan for input

    if (move[1] != '\n'){  // check for invalid input
        printf("\nMyERROR: An illegal operation was performed, so I have to stop the program.\n");
        exit(1);
    }
    switch (move[0]){
        case 'D':
            if ((*playerrow) < (GRID_SIZE - 1)){  // cant move down if at bottom of grid
                (*playerrow)++;
                (*moves)++;
            }
            else{
                printf("\nInvalid move\n");
                (*moves)++;}
            break;
        case 'U':
            if ((*playerrow) > 0){  // cant move up if at top of grid
                (*playerrow)--;
                (*moves)++;
            }
            else{
                printf("\nInvalid move\n"); 
                (*moves)++;}
            break;
        case 'L':
            if ((*playercol) > 0){  // cant move left if at left of grid
                (*playercol)--;
                (*moves)++;
            }
            else{
                printf("\nInvalid move\n");
                (*moves)++;}
            break;
        case 'R':
            if ((*playercol) < (GRID_SIZE - 1)){  // cant move right if at right of grid
                (*playercol)++;
                (*moves)++;
            }
            else{
                printf("\nInvalid move\n");
                (*moves)++;}
            break;
        default:
            printf("\nInvalid move\n");
            (*moves)++;
            break;
    }
    if (grid[*playerrow][*playercol] == 'T'){
        (*treasuresFound)++;
        grid[*playerrow][*playercol] = '_';
    }
}


int main(int argc, char *argv[]){

    int playercol, playerrow, moves = 0, treasuresFound = 0, c;
    char grid[GRID_SIZE][GRID_SIZE];
    srand(2024);    // seed random number generator (we use same seed to get same results)

    // initialize grid, treasures, and player
    grid_init(grid);
    treasure_init(grid);
    Player_init(&playerrow, &playercol);

    // print initial grid
    printf("\n");
    print_turn(grid, &playerrow, &playercol, &moves, &treasuresFound);

    // play game
    while (moves < MAX_MOVES && treasuresFound < TREASURE_COUNT)
    {
        turn(grid, &playerrow, &playercol, &moves, &treasuresFound);
        print_turn(grid, &playerrow, &playercol, &moves, &treasuresFound);
    }
    

    if (treasuresFound == TREASURE_COUNT){
        printf("Congratulations! You found all the treasures.\n");
        printf("You took %d moves.\n", moves);}
    else
        printf("Sorry, you ran out of moves.\n");
    return 0;
}
