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
// new function (test needed)
void getSimCode(int arr[]) {
    char input[6];  // Array to hold the input string

    printf("Simulation senario code: Enter Five digits without spaces (1-5): ");
    scanf("%5s", input);  // Read a string of 5 characters

    for (int i = 0; i < 5; i++) {
        if (input[i] >= '1' && input[i] <= '5') {  // Check if the character is a digit between 1 and 5
            arr[i] = input[i] - '0';  // Convert the character to an integer
        } else {
            printf("Invalid input. Please enter digits from 1 to 5 only.\n");
            return;
        }
    }
}

void drawRoom(const SmartHomeState *state){
    char brightnessA[5] = "", brightnessB[5] = "", temperature[10] = "";

    for (int i = 0; i < state->dimmerALevel; i++){
        brightnessA[i] = '*';
    }
    brightnessA[state->dimmerALevel] = '\0';  // Terminate the string

    for (int i = 0; i < state->dimmerBLevel; i++){
        brightnessB[i] = '*';
    }
    brightnessA[state->dimmerALevel] = '\0';  // Terminate the string

    for (int i = 0; i < state->temperatureRoomLevel; i++){
        temperature[i] = '-';
    }

    if (state->lamp1 == false){  // if lamp1 is off
        printf("Lamp 1: -\n");
    }
    else{
        printf("Lamp 1: *%s\n", brightnessA);
    }

    if (state->lamp2 == false){  // if lamp2 is off
        printf("Lamp 2: -\n");
    }
    else{
        printf("Lamp 2: *%s\n", brightnessA);
    }

    if (state->lamp3 == false){  // if lamp3 is off
        printf("Lamp 3: -\n");
    }
    else{
        printf("Lamp 3: *%s\n", brightnessB);
    }
    printf("Temperature: -%s\n", temperature);
}
