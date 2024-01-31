#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep function

// Define a structure for the smart home state
typedef struct {
    bool lamp1;
    bool lamp2;
    bool lamp3;
    int dimmerALevel; // 0 to 4
    int dimmerBLevel; // 0 to 4
    int temperatureRoomLevel; // 0 to 9
} SmartHomeState;

// Function prototypes
void initializeSmartHome(SmartHomeState *state);
void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int dimmerB);
void updateTemperature(SmartHomeState *state, int temperature);
void printSmartHomeState(const SmartHomeState *state);
void drawRoom(const SmartHomeState *state);
bool isValidInput(char d);
void getSimCode(int arr[]);


int main() {
    SmartHomeState state;
	int i, simcode[5];
	
	getSimCode(simcode);
	
    initializeSmartHome(&state);

    // Simulate different situations
    for (i = 0; i < 5; i++) {
		//updateLighting(&state, i % 2 == 0, i % 3 == 0, i % 4 == 0, i % 5, (4 - i) % 5);
		//printf("modolo i=%c, d1=%c   id1=%d  %d\n",i, d1, id1, i %  id1);
        updateLighting(&state, i % simcode[0] == 0, i % simcode[1] == 0, i % simcode[2] == 0, i % simcode[3], (4 - i) % simcode[4]);
        updateTemperature(&state, i);

        printSmartHomeState(&state);
        drawRoom(&state);

        sleep(1); // sleep for 1 second
    }

    return 0;
}

void initializeSmartHome(SmartHomeState *state) {
    state->lamp1 = false;
    state->lamp2 = false;
    state->lamp3 = false;
    state->dimmerALevel = 0;
    state->dimmerBLevel = 0;
    state->temperatureRoomLevel = 0;
}

void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int dimmerB) {
    state->lamp1 = lamp1;
    state->lamp2 = lamp2;
    state->lamp3 = lamp3;
    state->dimmerALevel = dimmerA;
    state->dimmerBLevel = dimmerB;
}

void updateTemperature(SmartHomeState *state, int temperature) {
    state->temperatureRoomLevel = temperature;
}

void printSmartHomeState(const SmartHomeState *state) {
    printf("Room State:\n");
    printf("Lamps: 1[%s] 2[%s] 3[%s]\n",
        state->lamp1 ? "ON" : "OFF", 
        state->lamp2 ? "ON" : "OFF",
        state->lamp3 ? "ON" : "OFF");
    printf("Dimmer Levels: A[%d] B[%d]\n", state->dimmerALevel, state->dimmerBLevel);
    printf("Temperature: %d°C\n", state->temperatureRoomLevel);
}

void drawRoom(const SmartHomeState *state) {
    // Draw lamps
    for (int i = 1; i <= 3; i++) {
        bool isLampOn = (i == 1 && state->lamp1) || 
                        (i == 2 && state->lamp2) || 
                        (i == 3 && state->lamp3);
        int dimmerLevel = (i == 1 || i == 2) ? state->dimmerALevel : state->dimmerBLevel;

        printf("Lamp %d: ", i);
        if (isLampOn) {
            for (int j = 0; j < dimmerLevel + 1; j++) {
                printf("*");
            }
        } else {
            printf("-");
        }
        printf("\n");
    }

    // Draw temperature
    printf("Temperature: ");
    for (int i = 0; i < state->temperatureRoomLevel + 1; i++) {
        printf("-");
    }
    printf("\n");
}

bool isValidInput(char d) {
    return d >= '1' && d <= '5';
}

void getSimCode(int arr[])
{
	char i, d1, d2,d3,d4,d5;
	int id1,id2,id3,id4,id5;
	
	//printf("\nEnter 3 digits simulation code where each digit should be from 2 up to 5 : ");
	while (1) {
        printf("Simulation senario code: Enter Five digits without spaces (1-5): ");
        scanf(" %c%c%c%c%c", &d1, &d2,  &d3,  &d4,  &d5);

       if (isValidInput(d1) && isValidInput(d2) && isValidInput(d3)&& isValidInput(d4)&& isValidInput(d5)) {
            break; // Break the loop if all inputs are valid
        } else {
            printf("Invalid input. Please enter digits from 1 to 5 only.\n");
        }
    }
	arr[0]=d1-'0';
	arr[1]=d2-'0';
	arr[2]=d3-'0';
	arr[3]=d4-'0';
	arr[4]=d5-'0';
 
    printf("You entered: %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3] ,arr[4]);
}
