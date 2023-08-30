#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rdd;
    mt19937 genn(rdd());
    uniform_int_distribution<> dis1(1, 10);
    uniform_int_distribution<> diss(1, 100 * dis1(genn));

    int num = diss(genn);
    int userInput = 0;
    cout << "Guess a number between 1 and " << diss.max() << " :" << endl;
    do {
        cin >> userInput;
        if (userInput < num)
            cout << "Too Low!" << endl;
        else if (userInput > num)
            cout << "Too High!" << endl;
    } while (num != userInput);
    cout << "That's it !!" << endl;
    return 0;
}
