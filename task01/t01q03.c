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
void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int dimmerB);
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
// for int x temperture = x-1, dimmerA = x-1, dimmerB = 5-x, 
// insert functions from prototype

void initializeSmartHome(SmartHomeState *state){
    state->lamp1 = false;
    state->lamp2 = false;
    state->lamp3 = false;
    state->dimmerALevel = 0;
    state->dimmerBLevel = 0;
    state->temperatureRoomLevel = 0;
}

void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int dimmerB){
    state->lamp1 = lamp1;
    state->lamp2 = lamp2;
    state->lamp3 = lamp3;
    state->dimmerALevel = dimmerA;
    state->dimmerBLevel = dimmerB;
}

void updateTemperature(SmartHomeState *state, int temperature){
    state->temperatureRoomLevel = temperature;
}

void printSmartHomeState(const SmartHomeState *state){
    printf("Room State:\n");
    printf("Lamps: 1[%s] 2[%s] 3[%s]\n", state->lamp1 ? "ON" : "OFF", state->lamp2 ? "ON" : "OFF", state->lamp3 ? "ON" : "OFF");
    printf("Dimmer Levels: A[%d] B[%d]\n", state->dimmerALevel, state->dimmerBLevel);
    printf("Temperature: %d°C\n", state->temperatureRoomLevel); 
}
