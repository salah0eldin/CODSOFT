#include <iostream>
#include <random>
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
        
        random_device rdd;
        mt19937 genn(rdd());
        uniform_int_distribution<> dis1(1, 10);
        uniform_int_distribution<> diss(1, 100 * dis1(genn));

        int num = diss(genn);
        int userInput = 0;
        cout << "Guess a number between 1 and " << diss.max() << " :" << endl;
        do
        {
            cin >> userInput;
            if (userInput < num)
                cout << "Too Low!" << endl;
            else if (userInput > num)
                cout << "Too High!" << endl;
        } while (num != userInput);
        cout << "That's it !!" << endl;
    } while (ask());
    return 0;
}