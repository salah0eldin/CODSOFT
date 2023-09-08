#include <iostream>
#include <limits>
#include <vector>
#include <string>
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

void ViewTasks(vector<pair<string, bool>> tasks);
void AddTask(vector<pair<string, bool>> &tasks);
void RemoveTask(vector<pair<string, bool>> &tasks);
void MarkTask(vector<pair<string, bool>> &tasks);

int main()
{
    vector<pair<string, bool>> tasks;
    char userInput;
    while (true)
    {
        clearScreen();
        cout << " ----------------------------------" << endl
             << "| The number of tasks : " << tasks.size() << endl
             << "|" << endl
             << "| View Tasks : (V,v)" << endl
             << "| Add a Task : (A,a)" << endl
             << "| remove a task : (R,r)" << endl
             << "| mark a task as done : (M,m)" << endl
             << " ----------------------------------" << endl;
        cin >> userInput;
        fflush(stdin);
        switch (userInput)
        {
        case 'V':
        case 'v':
            clearScreen();
            ViewTasks(tasks);
            cout << endl
                 << "To go back enter any character" << endl;
            cin >> userInput;
            fflush(stdin);
            break;
        case 'A':
        case 'a':
            AddTask(tasks);
            break;
        case 'R':
        case 'r':
            RemoveTask(tasks);
            break;
        case 'M':
        case 'm':
            MarkTask(tasks);
            break;
        }
    }
    return 0;
}

void ViewTasks(vector<pair<string, bool>> tasks)
{
    if (tasks.size() == 0)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << "- " << tasks[i].first;
            if (tasks[i].second)
                cout << "  (" << char(251) << ")";
            cout << endl;
        }
    }
}

void AddTask(vector<pair<string, bool>> &tasks)
{
    string task;
    cout << endl
         << "Enter task :" << endl
         << endl;
    getline(cin, task);
    fflush(stdin);
    tasks.push_back({task, false});
}

void RemoveTask(vector<pair<string, bool>> &tasks)
{
    if (tasks.size() == 0)
    {
        cout << "The list is empty" << endl;
        Sleep(1000);
    }
    else
    {
        int x;
        clearScreen();
        ViewTasks(tasks);
        cout << endl
             << "Enter the number of the tasks you want to remove: ";
        cin >> x;
        cin.ignore();
        if (cin.fail() || x < 1 || x > tasks.size())
        {
            cout << "Wrong index or Invalid input" << endl;
            Sleep(1000);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            tasks.erase(tasks.begin() + x - 1);
    }
}

void MarkTask(vector<pair<string, bool>> &tasks)
{
    if (tasks.size() == 0)
    {
        cout << "The list is empty" << endl;
        Sleep(1000);
    }
    else
    {
        int x;
        clearScreen();
        ViewTasks(tasks);
        cout << endl
             << "Select a task by its number to mark : ";
        cin >> x;
        cin.ignore();
        if (cin.fail() || x < 1 || x > tasks.size())
        {
            cout << "Wrong index or Invalid input" << endl;
            Sleep(1000);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            tasks[x - 1].second = true;
    }
}
