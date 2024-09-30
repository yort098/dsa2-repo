// A2p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum SortingMethod {
    bubble = 1,
    selection = 2,
    insertion = 3,
    merge = 4,
    quick = 5,
};

template <typename T>
void BubbleSort(T arr[], int size);

template <typename T>
void SelectionSort(T arr[], int size);

template <typename T>
void InsertionSort(T arr[], int size);

template <typename T>
void MergeSort(T arr[], int left, int right);

template <typename T>
void Merge(T arr[], int left, int mid, int right);

template <typename T>
int Partition(T arr[], int low, int high);

template <typename T>
void QuickSort(T arr[], int low, int high);

template <typename T>
void printArray(T arr[], int size);

int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90};
    const int arrSize = sizeof(arr) / sizeof(arr[0]);
    int input = -1;

    cout << "Unsorted array: ";
    printArray(arr, arrSize);

    do
    {
        cout << "Please Select a sorting algorithm:\n";
        cout << "1: Bubble\t2: Selection\t3. Insertion\t4. Merge\t5. Quick\n";

        cin >> input;
        cout << endl;
    } while (input < 1 || input > 5);

    switch (input)
    {
    case bubble:
        cout << "Initializing Bubble Sort" << endl;
        BubbleSort(arr, arrSize);

        cout << "Sorted Array: ";
        printArray(arr, arrSize);
        break;

    case selection:
        cout << "Initializing Selection Sort" << endl;
        SelectionSort(arr, arrSize);

        cout << "Sorted Array: ";
        printArray(arr, arrSize);
        break;

    case insertion:
        cout << "Initializing Insertion Sort" << endl;
        InsertionSort(arr, arrSize);

        cout << "Sorted Array: ";
        printArray(arr, arrSize);
        break;

    case merge:
        cout << "Initializing Merge Sort" << endl;
        MergeSort(arr, 0, arrSize-1);

        cout << "Sorted Array: ";
        printArray(arr, arrSize);
        break;

    case quick:
        cout << "Initializing QuickSort" << endl;
        QuickSort(arr, 0, arrSize-1);

        cout << "Sorted Array: ";
        printArray(arr, arrSize);
        break;
    }
}

template <typename T>
void BubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
            }
        }
    }
}

template <typename T>
void SelectionSort(T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int arrMinIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[arrMinIndex])
            {
                arrMinIndex = j;
            }
        }

        if (arrMinIndex != i)
        {
            T temp = arr[i];
            arr[i] = arr[arrMinIndex];
            arr[arrMinIndex] = temp;
        }
    }
}

template <typename T>
void InsertionSort(T arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int current = i;
        while (arr[current] < arr[current - 1] && current > 0)
        {
            T temp = arr[current];
            arr[current] = arr[current - 1];
            arr[current - 1] = temp;

            current--;
        }
    }
}

template <typename T>
void Merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary arrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = left; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void MergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        Merge(arr, left, mid, right);
    }
}

// Partition function that takes the middle element as the pivot
template <typename T>
int Partition(T arr[], int low, int high) {
    int mid = low + (high - low) / 2;  // Calculate the middle index
    T pivot = arr[mid];                // Use the middle element as the pivot

    // Move the pivot element to the end temporarily
    T temp = arr[mid];
    arr[mid] = arr[high];
    arr[high] = temp;

    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // Increment index of smaller element
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Move pivot to its correct position
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// QuickSort function
template <typename T>
void QuickSort(T arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = Partition(arr, low, high);

        // Recursively sort elements before and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

template<typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ", ";
    }

    cout << "\n" << endl;
}
