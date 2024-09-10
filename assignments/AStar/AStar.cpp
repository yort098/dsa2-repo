// Troy Hamilton -- A* in C++
// 
// Resources Used:  I mainly based my code off of Austin Willoughby's A* in JavaScript example
//                  that he provided us last semester. I also *sparingly* used ChatGPT to answer
//                  questions about bugs that I was getting stuck on for a long time. For example, I
//                  couldn't figure out why I was getting memory leaks or how to fix them, so
//                  ChatGPT told me to use smart pointers instead! After a quick pivot, all of my
//                  memory leaks were gone. There were a couple other similar instances, but 
//                  I never copy-pasted any code! There were also a couple things I looked up on Google that
//                  weren't as significant like how to change the color of the console.
//
// Notes:           The input in the console doesn't account for non-numbers inputted because I didn't have the
//                  time for it (just don't try it please). 
//                  Also, you can input high numbers for the width and height, but I wouldn't recommend it, 
//                  only because it just takes.. forever to print out the grid each time in the console.

#include "Cell.h"
#include "Grid.h"

#include <iostream>
#include <vector>
#include <time.h>
#include <memory>
using namespace std;

// Making sure all memory is cleared
// after program finishes
void wrapper()
{
    // Seeding random
    srand(time(NULL));

    cout << "Welcome to the C++ A* Console Simulator!\n" << endl;

    unsigned short width = 0;
    do
    {
        cout << "Please enter a non-negative width for the grid: ";
        cin >> width;
    } while (width <= 0);
    
    unsigned short height = 0;
    do
    {
        cout << "Please enter a non-negative height for the grid: ";
        cin >> height;
    } while (height <= 0);

    // Initializing the grid
    Grid grid(width, height);

    cout << "This is your grid: " << endl;
    grid.Draw();
    system("pause"); // "pauses" the console until the user presses a button

    unsigned int num;
    // These are shared pointers so that they can be referenced by other classes
    shared_ptr<vector<int>> startPoint = make_shared<vector<int>>();
    shared_ptr<vector<int>> endPoint = make_shared<vector<int>>();

    // Customizing the grid
    do
    {
        cout << "Please enter a starting x coordinate (between 0-" << width - 1 << "): ";
        cin >> num;

    } while (num < 0 || num > width - 1);

    startPoint->push_back(num);

    do
    {
        cout << "Please enter a starting y coordinate (between 0-" << height - 1 << "): ";
        cin >> num;

    } while (num < 0 || num > height - 1);

    startPoint->push_back(num);

    cout << endl;

    do
    {
        cout << "Please enter a ending x coordinate (between 0-" << width - 1 << "): ";
        cin >> num;
    } while (num < 0 || num > width - 1);
  
    endPoint->push_back(num);

    do
    {
        cout << "Please enter a ending y coordinate (between 0-" << height - 1 << "): ";
        cin >> num;
    } while (num < 0 || num > height - 1);
    
    endPoint->push_back(num);

    cout << "This is your grid with start and end points: " << endl;
    grid.SetStartPoint(startPoint);
    grid.SetEndPoint(endPoint);
    grid.Draw();
    system("pause");

    unsigned short numObstacles = 0;
    do
    {
        cout << "Please enter a number of walls to add (between 0-" << (width * height) - 2 << "): ";
        cin >> numObstacles;
    } while (numObstacles < 0 || numObstacles >(width * height) - 2); // -2 is to account for the start and end points

    cout << "This is your grid with random walls added: " << endl;
    grid.GenerateObstacles(numObstacles);
    grid.Draw();
    system("pause");

    // Works regardless of if a path is found or not
    cout << "Finding path..." << endl;
    system("pause");
    grid.FindPath();
}

int main()
{
    wrapper();

    // Making sure there's no memory leaks
    if (_CrtDumpMemoryLeaks())
    {
        cout << "Mem leaks!" << endl;
    }
}

