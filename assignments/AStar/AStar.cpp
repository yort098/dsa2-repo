#include "Cell.h"
#include "Grid.h"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Grid grid(4, 4);
    grid.Draw();

    int num;
    vector<unsigned int> startPoint;
    vector<unsigned int> endPoint;

    cout << "Please enter a starting x coordinate: ";
    cin >> num;
    startPoint.push_back(num);

    cout << "Please enter a starting y coordinate: ";
    cin >> num;

    startPoint.push_back(num);

    cout << endl;

    cout << "Please enter a target x coordinate: ";
    cin >> num;
    endPoint.push_back(num);

    cout << "Please enter a target y coordinate: ";
    cin >> num;

    endPoint.push_back(num);
}

