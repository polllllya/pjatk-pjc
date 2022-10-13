#define POL
//#define ENG

#if  defined(POL) && defined(ENG)
    #error Please define only one language
#elif !(defined(POL) || defined(ENG))
    #error Please define a language
#endif

#ifdef POL
    #define input "wprowadz liczbe naturalna (0 jeśli gotowe): "
    #define output "maksymalna suma cyfr wynosila: "
#elif defined(ENG)
    #define input "enter a natural number (0 if done): "
    #define output "max sum of digits was: "
#endif

#include <iostream>

using namespace std;

int main() {

    int number;
    int current_sum;
    int current_number;

    int max_sum = 0;
    int max_number = 0;

    do {
        cout << input;
        cin >> number;
        current_sum = 0;
        current_number = number;

        while (number / 10 > 0) {
            current_sum += number % 10;
            number /= 10;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_number = current_number;
        }
    } while (number != 0);

    cout << output << max_sum << " - " << max_number;
}
