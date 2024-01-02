#include <iostream>
#include <thread> //using a seperate thread to check for stop loop flag, allowing the main loop to keep running
#include <conio.h> // For _kbhit and _getch

bool running = true;
int* ptr = nullptr;

void checkInput() {
    while (running) {
        if (_kbhit()) {
            char key = _getch();

            if (key == 'F' || key == 'f') {
                running = false;
                delete ptr;
            }
        }
    }
}

int main() {
    std::thread inputThread(checkInput);

    printf("Running memory leak simulation...\nPress F to stop\n");

    while (running) {
        int* ptr = new int;  // dynamically allocate memory 
    }

    inputThread.join();  // Wait for input thread to finish

    printf("Simulation stopped.\n");

    return 0;
}