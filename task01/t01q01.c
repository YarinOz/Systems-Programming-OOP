#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 3
#define TREASURE_COUNT 6
#define MIN_TREASURE_COUNT 5
#define MAX_MOVES 20

int treasuresFound = 0;

int main(int argc, char *argv[]){

    // insert code here  //
    // INIT + Algorithem:
    // possible_values = ['T', '_', 'P']; in the grid we see Treasure, _Blank, Player
    // grid = char array[GRID_SIZE][GRID_SIZE];
    // initialize grid with '_'
    // possible_moves = ['U', 'D', 'L', 'R']; Up, Down, Left, Right {map to [[i-1][j], [i+1][j], [i][j-1], [i][j+1]]}
    // srand(2024); create a random seed
    // int randrow = rand() % 3;
    // int randcol = rand() % 3;
    // Randomize P location:
    // grid[randrow][randcol] = 'P';
    // Randomize Treasures:
    // treasureGen(grid, TREASURE_COUNT)  generate 6 random Treasures
    // Flow: map generated -> player moves U,D,L,R until (20 moves exceeded | found at least 5 treasures) 


    if (treasuresFound >= MIN_TREASURE_COUNT)
        printf("\nCongratulations! You found all the treasures.\n");
    else
        printf("\nSorry, you ran out of moves.\n");
    return 0;
}
