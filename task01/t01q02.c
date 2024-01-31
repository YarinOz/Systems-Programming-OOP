#include <stdio.h>
#include <string.h>

#define MAX_FLOORS 10

void num_map(int floorNumber, char Floors[MAX_FLOORS][10]){
    if (floorNumber < 0 || floorNumber > MAX_FLOORS){
        printf("\nYou requested to go to the Number is out of range.\n");
    }else
        printf("You requested to go to the %s floor\n", Floors[floorNumber]);
}

void elevator(int currentFloor, int nextFloor){
    if (currentFloor < nextFloor){
        // printf("Elevator is going up\n");
        while (currentFloor < nextFloor){
            currentFloor++;
            printf("Passing Floor %d\n", currentFloor);
        }
    }
    else if (currentFloor > nextFloor){
        // printf("Elevator is going down\n");
        while (currentFloor > nextFloor){
            currentFloor--;
            printf("Passing Floor %d\n", currentFloor);
        }
    }
    printf("Arrived at Floor %d\n", currentFloor);
}

int main(int argc, char *argv[]){
    int currentFloor = 0;
    float nextFloor;
    char Floors[MAX_FLOORS][10] = {"Zeroth", "First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth"};
    printf("Elevator is currently at floor: %d\n", currentFloor);
    while (1){
        printf("Enter the floor number you wish to go to (-1 to exit): ");
        int result = scanf("%f", &nextFloor);

        if (nextFloor == -1){
            break;
        }
        ////////////// check what to return on input s.a A,B,C... ^,%,$,#.. 2.5, 1.9... //////////////

        if (nextFloor - (int)nextFloor != 0 || result == 0) {       // Exit if input is not an integer
            printf("\nMyERROR: An illegal operation was performed, so I have to stop the program.\n");
            break ;
        } else if (nextFloor < 0 || nextFloor > MAX_FLOORS){  // Skip if input is out of range
            printf("\nInvalid floor number.\n");
            continue;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        num_map(nextFloor, Floors);

        nextFloor = (int)nextFloor;
        elevator(currentFloor, nextFloor);
        currentFloor = nextFloor;
    }

    printf("Elevator simulation ended.\n");
    
    return 0;
}
