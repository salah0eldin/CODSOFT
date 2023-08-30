#include <iostream>
#include <cmath>

#ifdef _WIN32

#include <windows.h>

#else
#include <cstdlib>
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char againInput = 1;
    while (againInput != '0') {
        clearScreen();

        string line = "";
        char operation = 0;
        int index = 0, opIndex = 0;
        bool flagIsCorrect = true;
        cout << endl << " --------------------------------------------------------" << endl;
        cout << "| Enter your Operation in this form :" << endl
             << "| num1 operator num2" << endl
             << "| ex: 1224.5 (+,-,*,/,^) 3432" << endl
             << "| NOTE: spaces between numbers and the operation doesn't affect" << endl;
        cout << " --------------------------------------------------------" << endl << endl;
        getline(cin, line);

        for (; index < line.length() && flagIsCorrect; index++) {
            char c = line[index];
            if (c == 94 || c == 47 || (c >= 42 && c <= 45 && c != ',')) {
                if (!operation) {
                    operation = c;
                    opIndex = index;
                } else
                    flagIsCorrect = 0;
            } else if (!isdigit(c) && c != '.' && c != ' ')
                flagIsCorrect = 0;
        }

        if (operation && flagIsCorrect) {
            float num1 = stof(line.substr(0, opIndex));
            float num2 = stof(line.substr(opIndex + 1, line.length() - opIndex));
            cout << "Answer is: ";
            switch (operation) {
                case '+':
                    cout << num1 + num2;
                    break;
                case '-':
                    cout << num1 - num2;
                    break;
                case '*':
                    cout << num1 * num2;
                    break;
                case '/':
                    cout << num1 / num2;
                    break;
                case '^':
                    cout << pow(num1, num2);
                    break;
            }
        } else {
            cout << "Wrong Formation";
        }
        cout << endl << endl << " --------------------------------------------------------" << endl;
        cout << "| For another Operation hit character" << endl
             << "| For EXIT enter 0:" << endl;
        cout << " --------------------------------------------------------" << endl;
        cin >> againInput;
        getchar();
        cout << endl;
    }
    return 0;
}

