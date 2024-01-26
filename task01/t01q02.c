#include <stdio.h>
#include <string.h>

#define MAX_FLOORS 10

void num_map(int floorNumber){
    switch (floorNumber) {
        case 0:
            printf("You requested to go to the Zeroth floor\n");
            break;
        case 1:
            printf("You requested to go to the First floor\n");
            break;
        case 2:
            printf("You requested to go to the Second floor\n");
            break;
        case 3:
            printf("You requested to go to the Third floor\n");
            break;
        case 4:
            printf("You requested to go to the Fourth floor\n");
            break;
        case 5:
            printf("You requested to go to the Fifth floor\n");
            break;
        case 6:
            printf("You requested to go to the Sixth floor\n");
            break;
        case 7:
            printf("You requested to go to the Seventh floor\n");
            break;
        case 8:
            printf("You requested to go to the Eighth floor\n");
            break;
        case 9:
            printf("You requested to go to the Ninth floor\n");
            break;
        default:
            printf("You requested to go to the Number is out of range.\n");
    }
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
    printf("Elevator is currently at floor: %d\n", currentFloor);
    while (1){
        printf("Enter the floor number you wish to go to (-1 to exit): \n");
        // int result = scanf("%d", &nextFloor);
        int result = scanf("%f", &nextFloor);
        num_map(nextFloor);
        if (nextFloor == -1){
            break;
        }
        ////////////// check what to return on input s.a A,B,C... ^,%,$,#.. 2.5, 1.9... //////////////
        if (result == 0) {
            printf("\nInvalid floor number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }  // Clear input buffer
            continue;
        
        } else if (nextFloor < 0 || nextFloor > MAX_FLOORS || nextFloor - (int)nextFloor != 0) { // Check if 0>input or input>10 or is not an integer
            printf("\nInvalid floor number.\n");
            continue;}
        ////////////////////////////////////////////////////////////////////////////////////////////
        nextFloor = (int)nextFloor;
        elevator(currentFloor, nextFloor);
        currentFloor = nextFloor;
    }

    printf("Elevator simulation ended.\n");
    
    return 0;
}
