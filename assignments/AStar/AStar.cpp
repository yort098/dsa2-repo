#include "Cell.h"
#include "Grid.h"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    vector<int>* startPoint = new vector<int>();

    vector<int>* endPoint = new vector<int>();

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

    delete startPoint;
    delete endPoint;
}

