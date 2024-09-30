#include <iostream>

template <class T>
struct Node {
    T data;
    struct Node* next;
};

using namespace std;

// Class
// To represent stack using template by class
// taking class in template
template <class T> class Stack {

public:
    // Empty constructor
    Stack();
    ~Stack();

    // Method 1
    // To add element to stack which can be any type
    // using stack push() operation
    void push(T k);

    // Method 2
    // To remove top element from stack
    // using pop() operation
    T pop();

    // Method 3
    // To print top element in stack
    // using peek() method
    T topElement();

    // Method 4
    // To check whether stack is empty
    // using isEmpty() method
    bool isEmpty();

private:
    Node<T>* head;
    int size;
};

// Method 6
// To initialise top to
// -1(default constructor)
template <class T> Stack<T>::Stack() 
{ 
    size = 0;
    head = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
    Node<T>* curr = head;
    Node<T>* next;

    while (curr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

// Method 7
// To add element element k to stack
template <class T> void Stack<T>::push(T k)
{

    // Inserted element
    cout << "Inserted element " << k << endl;

    Node<T>* newNode = new Node<T>();
    newNode->data = k;
    newNode->next = NULL;

    // If the head is NULL just assign it to newNode();
    if (head == NULL) {

        head = newNode;

    }
    else {

        newNode->next = head;
        head = newNode;
    }

    size++;
}

// Method 8
// To check if the stack is empty
template <class T> bool Stack<T>::isEmpty()
{
    return size <= 0;
}

// Utility methods

// Method 10
template <class T> T Stack<T>::pop()
{
    if (!isEmpty())
    {
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        size--;
        delete temp;

        // Returning the element/s that is/are popped
        return data;
    }
    
}

// Method 11
template <class T> T Stack<T>::topElement()
{
    // Initialising a variable to store top element
    T top_element = head->data;

    // Returning the top element
    return top_element;
}

void wrapper()
{
    // Creating object of Stack class in main() method
    // Declaring objects of type Integer and String
    Stack<int> integer_stack;
    Stack<string> string_stack;

    // Adding elements to integer stack object
    // Custom integer entries
    integer_stack.push(2);
    integer_stack.push(54);
    integer_stack.push(255);

    // Adding elements to string stack
    // Custom string entries
    string_stack.push("Copied");
    string_stack.push("from");
    string_stack.push("GeeksforGeeks");

    // Now, removing element from integer stack
    cout << integer_stack.pop() << " is removed from stack"
        << endl;

    // Removing top element from string stack
    cout << string_stack.pop() << " is removed from stack "
        << endl;

    // Print and display the top element in integer stack
    cout << "Top element is " << integer_stack.topElement()
        << endl;

    // Print and display the top element in string stack
    cout << "Top element is " << string_stack.topElement()
        << endl;
}

int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks())
    {
        cout << "Mem leaks!" << endl;
    }

    return 0;
}
