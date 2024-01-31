#include <stdio.h>
#include <string.h>

#define MAX_FLOORS 10

const char* numberToTextName(int number) {
    // Array of text names for numbers 0 to 10
    const char *numbersToText[] = {
        "Zeroth floor", "First floor", "Second floor", "Third floor", 
        "Fourth floor", "Fifth floor", "Sixth floor", "Seventh floor", 
        "Eighth floor", "Ninth floor", "Tenth floor"
    };

    // Check if the number is in the valid range
    if (number >= 0 && number <= 10) {
        return numbersToText[number];
    } else {
        return "Number is out of range.";
    }
}


int main() {
    int currentFloor = 0;
    int floors[MAX_FLOORS];
    int destination, i;

    // Initialize floors
    for (i = 0; i < MAX_FLOORS; i++) {
        floors[i] = i;
    }

    printf("Elevator is currently at floor: %d\n", currentFloor);

    while (1) {
        printf("Enter the floor number you wish to go to (-1 to exit): ");
        scanf("%d", &destination);
		printf("\nYou requested to go to the %s\n",numberToTextName(destination));
		
        if (destination == -1) break;

        if (destination < 0 || destination >= MAX_FLOORS) {
            printf("\nInvalid floor number.\n");
            continue;
        }

        while (currentFloor != destination) {
            if (currentFloor < destination) {
                currentFloor++;
            } else {
                currentFloor--;
            }
            printf("Passing Floor %d\n", currentFloor);
        }

        printf("Arrived at Floor %d\n", currentFloor);
    }

    printf("Elevator simulation ended.\n");

    return 0;
}
