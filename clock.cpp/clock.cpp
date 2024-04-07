*/
*clock.cpp
*
* Date: 02 / 19 / 2024
* Author : Lorenzo Ginyard
*

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    void setHours(int h) {
        hours = h % 24;
    }

    void setMinutes(int m) {
        minutes = m % 60;
    }

    void setSeconds(int s) {
        seconds = s % 60;
    }

    void displayTime() {
        cout << setfill('0') << setw(2) << hours << ":"
            << setfill('0') << setw(2) << minutes << ":"
            << setfill('0') << setw(2) << seconds << endl;
    }

    void addHour() {
        hours = (hours + 1) % 24;
    }

    void addMinute() {
        minutes = (minutes + 1) % 60;
    }

    void addSecond() {
        seconds = (seconds + 1) % 60;
    }
};

int main() {
    Clock clock1, clock2;

    int hours, minutes, seconds;
    cout << "Enter initial time for Clock 1 (hh:mm:ss): ";
    cin >> hours >> minutes >> seconds;
    clock1.setHours(hours);
    clock1.setMinutes(minutes);
    clock1.setSeconds(seconds);

    cout << "Enter initial time for Clock 2 (hh:mm:ss): ";
    cin >> hours >> minutes >> seconds;
    clock2.setHours(hours);
    clock2.setMinutes(minutes);
    clock2.setSeconds(seconds);

    bool exitFlag = false;
    char choice;

    while (!exitFlag) {
        system("clear");

        cout << "Clock 1: ";
        clock1.displayTime();
        cout << "Clock 2: ";
        clock2.displayTime();

        cout << "\nMenu:\n";
        cout << "1. Add an hour\n";
        cout << "2. Add a minute\n";
        cout << "3. Add a second\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            clock1.addHour();
            clock2.addHour();
            break;
        case '2':
            clock1.addMinute();
            clock2.addMinute();
            break;
        case '3':
            clock1.addSecond();
            clock2.addSecond();
            break;
        case '4':
            exitFlag = true;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        // Delay for 1 second before displaying the updated time
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}