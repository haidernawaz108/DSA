#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // for rand() and srand()
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function with random pivot selection
int partitionRandom(vector<int> &arr, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1); // Random index between low and high
    swap(arr[randomPivotIndex], arr[high]); // Swap random pivot with the last element
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Partition function with last element as pivot
int partitionLast(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRandom(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, pivotIndex - 1);
        quickSortRandom(arr, pivotIndex + 1, high);
    }
}

void quickSortLast(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionLast(arr, low, high);
        quickSortLast(arr, low, pivotIndex - 1);
        quickSortLast(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    int n = arr.size();

    // Initialize random seed
    srand(time(0));

    cout << "ORIGINAL ARRAY: ";
    printArray(arr);

    // Measure time for Quick Sort with last element as pivot
    vector<int> arrLast = arr;
    clock_t startLast = clock();
    quickSortLast(arrLast, 0, n - 1);
    clock_t endLast = clock();
    double timeLast = double(endLast - startLast) / CLOCKS_PER_SEC;

    cout << "SORTED ARRAY WITH LAST ELEMENT AS PIVOT: ";
    printArray(arrLast);
    cout << "TIME TAKEN BY QUICK SORT (Last Element Pivot): " << timeLast << " SECONDS" << endl;

    // Measure time for Quick Sort with random pivot
    vector<int> arrRandom = arr;
    clock_t startRandom = clock();
    quickSortRandom(arrRandom, 0, n - 1);
    clock_t endRandom = clock();
    double timeRandom = double(endRandom - startRandom) / CLOCKS_PER_SEC;

    cout << "SORTED ARRAY WITH RANDOM PIVOT: ";
    printArray(arrRandom);
    cout << "TIME TAKEN BY QUICK SORT (Random Pivot): " << timeRandom << " SECONDS" << endl;

    return 0;
}
