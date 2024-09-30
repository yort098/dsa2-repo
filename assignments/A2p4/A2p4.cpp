// A2p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T>
class Queue 
{
public:
    Queue(int capacity);
    ~Queue();

    void Enqueue(T data);
    void Dequeue();

    bool isFull();

    void Print();
private:
    int frontIndex, backIndex, maxSize;
    T* queue;
};

template<class T>
Queue<T>::Queue(int maxSize)
{
    this->maxSize = maxSize;
    queue = new T[maxSize];

    frontIndex = 0;
    backIndex = -1;
}

template<class T>
Queue<T>::~Queue()
{
    delete[] queue;
}

template<class T>
void Queue<T>::Enqueue(T data)
{
    if (isFull())
    {
        cout << "Queue is full!" << endl;
        return;
    }

    backIndex++;
    cout << "Adding " << data << " to the queue!" << endl;
    queue[backIndex] = data;
}

template<class T>
void Queue<T>::Dequeue()
{
    if (frontIndex > backIndex)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Removing '" << queue[frontIndex] << "' from the queue!" << endl;
    for (int i = 0; i < backIndex; i++) {
        queue[i] = queue[i + 1];
    }

    backIndex--;
}

template<class T>
bool Queue<T>::isFull()
{
    return backIndex == maxSize -1;
}

template<class T>
void Queue<T>::Print()
{
    if (backIndex == -1)
    {
        cout << "Queue is currently empty." << endl;
        return;
    }

    cout << "The current queue, in order: ";
    for (int i = frontIndex; i <= backIndex; ++i)
    {
        cout << queue[i] << ", ";
    }
    cout << endl;
}

void wrapper()
{
    cout << "Integer Queue testing:\n" << endl;
    Queue<int> intQueue(5);
    intQueue.Enqueue(40);
    intQueue.Enqueue(15);
    intQueue.Enqueue(32);
    intQueue.Enqueue(74);
    intQueue.Enqueue(13);
    intQueue.Print();

    cout << endl;

    intQueue.Dequeue();
    intQueue.Dequeue();
    intQueue.Dequeue();
    intQueue.Print();

    cout << endl;

    cout << "String Queue testing:\n" << endl;
    Queue<string> stringQueue(5);
    stringQueue.Enqueue("hello");
    stringQueue.Enqueue("this");
    stringQueue.Enqueue("is");
    stringQueue.Enqueue("me");
    stringQueue.Enqueue("testing");
    stringQueue.Print();

    cout << endl;

    stringQueue.Dequeue();
    stringQueue.Print();

    stringQueue.Enqueue("new!");
    stringQueue.Print();
    stringQueue.Enqueue("this shouldn't work");
}

int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks())
    {
        cout << "Mem leaks!" << endl;
    }
}


