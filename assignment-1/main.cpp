#include <iostream>

using namespace std;

int main() {
    int input;
    int current_number = 0;
    int count = 0;
    int max_times = 0;
    int number = 0;

    do {
        cout << "Enter the number(0 is the end): ";
        cin >> input;

        if (current_number != input) count = 0;

        count++;

        if (count > max_times) {
            max_times = count;
            number = input;
        }

        current_number = input;
    } while (input != 0);
    cout << "\n" << "Longest sequence: " << max_times << " times " << number;
}
