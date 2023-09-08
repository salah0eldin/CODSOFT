#include <iostream>
#include <cmath>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool ask()
{
    char c;
    cout << endl
         << " --------------------------------------------------------" << endl
         << "Again ? (1,0)" << endl;
    cin >> c;
    fflush(stdin);
    return (c == '0' ? false : true);
}

int main()
{
    do
    {
        clearScreen();

        string line = "";
        char operation = 0;
        int index = 0, opIndex = 0;
        bool flagIsCorrect = true;
        cout << endl
             << " --------------------------------------------------------------------" << endl;
        cout << "| Enter your Operation in this form :" << endl
             << "| num1 operator num2" << endl
             << "| operators: (+,-,*,/,^)"<<endl
             << "| ex: 12.4 - 34" << endl
             << "| NOTE: spaces between numbers and the operation doesn't affect" << endl;
        cout << " --------------------------------------------------------------------" << endl
             << endl;
        getline(cin, line);

        for (; index < line.length() && flagIsCorrect; index++)
        {
            char c = line[index];
            if (c == 94 || c == 47 || (c >= 42 && c <= 45 && c != ','))
            {
                if (!operation)
                {
                    operation = c;
                    opIndex = index;
                }
                else
                    flagIsCorrect = 0;
            }
            else if (!isdigit(c) && c != '.' && c != ' ')
                flagIsCorrect = 0;
        }

        if (operation && flagIsCorrect)
        {
            float num1 = stof(line.substr(0, opIndex));
            float num2 = stof(line.substr(opIndex + 1, line.length() - opIndex));
            cout << "Answer is: ";
            switch (operation)
            {
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
        }
        else
        {
            cout << "Wrong Formation";
        }
    } while (ask());
    return 0;
}