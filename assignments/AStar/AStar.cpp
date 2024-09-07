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

    
    cout << "Finding path..." << endl;
    grid.FindPath();
}

