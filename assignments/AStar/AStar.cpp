#include "Cell.h"
#include "Grid.h"

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    srand(NULL);

    int num;
    vector<unsigned short>* startPoint = new vector<unsigned short>();

    vector<unsigned short>* endPoint = new vector<unsigned short>();

    cout << "Please enter a starting x coordinate: ";
    cin >> num;
    startPoint->push_back(num);

    cout << "Please enter a starting y coordinate: ";
    cin >> num;

    startPoint->push_back(num);

    cout << endl;

    cout << "Please enter a target x coordinate: ";
    cin >> num;
    endPoint->push_back(num);

    cout << "Please enter a target y coordinate: ";
    cin >> num;

    endPoint->push_back(num);

    Grid grid(4, 4, startPoint, endPoint);
   // grid.CalculateHueristicCosts();
    grid.Draw();
    grid.FindPath();
}

