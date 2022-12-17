#include <iostream>

bool checkpass(const char *pass);

int main() {
    using std::cout;
    using std::endl;
    const char *passes[] =
            {
                    "AbcDe93", "A1b:A1b>", "Ab:Acb<",
                    "abc123><", "Zorro@123", nullptr
            };

    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}

bool checkpass(const char *pass) {

    //1
    bool goodLength;
    unsigned int size = 0;
    for (int i = 0; i < 9; i++) {
        if (pass[i] == 0) break;
        size++;
    }
    if (size > 7) goodLength = true;
    else std::cout << "Too short" << std::endl;


    //2
    bool differentSymbols = false;
    unsigned int count = 0;
    char symbol;
    bool isPresent;

    for (int i = 0; i < size; i++) {
        isPresent = false;
        symbol = pass[i];
        if (i != 0) {
            for (int y = i - 1; y >= 0; y--) {
                if (pass[y] == symbol) {
                    isPresent = true;
                    break;
                }
            }
        }
        if (!isPresent) {
            for (int k = i + 1; k < size; k++) {
                if (pass[k] == symbol) {
                    count++;
                }
            }
        }
    }

    if (size - count >= 6) differentSymbols = true;
    else std::cout << "Too few different characters" << std::endl;


    //3
    bool oneDigit = false;
    for (int i = 0; i < size; i++) {
        if ((int) pass[i] >= (int) '0' && (int) pass[i] <= (int) '9') {
            oneDigit = true;
            break;
        }
    }
    if (!oneDigit) std::cout << "No digit" << std::endl;


    //4
    bool bigLetter = false;
    for (int i = 0; i < size; i++) {
        if ((int) pass[i] >= (int) 'A' && (int) pass[i] <= (int) 'Z') {
            bigLetter = true;
            break;
        }
    }
    if (!bigLetter) std::cout << "No uppercase letter" << std::endl;


    //5
    bool smallLetter = false;
    for (int i = 0; i < size; i++) {
        if ((int) pass[i] >= (int) 'a' && (int) pass[i] <= (int) 'z') {
            smallLetter = true;
            break;
        }
    }
    if (!smallLetter) std::cout << "No lowercase letter" << std::endl;


    //6
    bool notNL = false; // not number not letter
    for (int i = 0; i < size; i++) {
        if ((int) pass[i] >= (int) '!' && (int) pass[i] <= (int) '/'
            || (int) pass[i] >= (int) ':' && (int) pass[i] <= (int) '@'
            || (int) pass[i] >= (int) '[' && (int) pass[i] <= (int) '`'
            || (int) pass[i] >= (int) '{' && (int) pass[i] <= (int) '~') {
            notNL = true;
            break;
        }
    }
    if (!notNL) std::cout << "No non-alphanumeric character" << std::endl;

    return goodLength && differentSymbols && oneDigit && bigLetter && smallLetter && notNL;
}
