#include "Cell.h"
#include "Grid.h"

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    srand(NULL);

    cout << "Welcome to the A* Console Simulator!\n" << endl;

    unsigned short width = 0;
    cout << "Please enter a width for the grid: ";
    cin >> width;

    unsigned short height = 0;
    cout << "Please enter a height for the grid: ";
    cin >> height;

    Grid grid(width, height);

    cout << "This is your grid: " << endl;
    grid.Draw();
    system("pause");

    int num;
    vector<unsigned short>* startPoint = new vector<unsigned short>();

    vector<unsigned short>* endPoint = new vector<unsigned short>();

    cout << "Please enter a starting x coordinate (between 0-" << width-1 << "): ";
    cin >> num;
    startPoint->push_back(num);

    cout << "Please enter a starting y coordinate (between 0-" << height - 1 << "): ";
    cin >> num;

    startPoint->push_back(num);

    cout << endl;

    cout << "Please enter a ending x coordinate (between 0-" << width - 1 << "): ";
    cin >> num;
    endPoint->push_back(num);

    cout << "Please enter a ending y coordinate (between 0-" << height - 1 << "): ";
    cin >> num;

    endPoint->push_back(num);

    cout << "This is your grid with start and end points: " << endl;
    grid.SetStartPoint(startPoint);
    grid.SetEndPoint(endPoint);
    grid.Draw();
    system("pause");

    unsigned short numObstacles = 0;
    cout << "Please enter a number of walls to add (between 0-" << (width*height) - 2 << "): ";
    cin >> numObstacles;

    cout << "This is your grid with random walls added: " << endl;
    grid.GenerateObstacles(numObstacles);
    grid.Draw();
    system("pause");
    
    cout << "Finding path..." << endl;
    system("pause");
    grid.FindPath();

    if (_CrtDumpMemoryLeaks())
    {
        cout << "Mem leaks!" << endl;
    }
}

