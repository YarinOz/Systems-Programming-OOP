#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> //For sleep function

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
void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int
dimmerB);
void updateTemperature(SmartHomeState *state, int temperature);
void printSmartHomeState(const SmartHomeState *state);
void drawRoom(const SmartHomeState *state);
bool isValidInput(char d);
void getSimCode(int arr[]);

int main() {
    SmartHomeState state;
    int i, simcode[5];

    getSimCode(simcode);//It convert from char digits into integer digits

    initializeSmartHome(&state);

    // Simulate different situations
    for (i = 0; i < 5; i++) {
    //update new home state base on the given code (e.g 24553)
    updateLighting(&state, i % simcode[0] == 0, i % simcode[1] == 0, i % simcode[2] == 0, i % simcode[3],
    (4 - i) % simcode[4]);
    updateTemperature(&state, i);

    printSmartHomeState(&state);
    drawRoom(&state);

    sleep(1); // sleep for 1 second
    }

    return 0;
}

// insert functions from prototype