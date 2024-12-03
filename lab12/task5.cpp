#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
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

// Utility function to generate a random array of given size
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }
    return arr;
}

// Function to measure and print execution time for Quick Sort with different pivots
void measureQuickSortPerformance(int size) {
    vector<int> arr = generateRandomArray(size);

    // Quick Sort with last element as pivot
    vector<int> arrLast = arr;
    clock_t startLast = clock();
    quickSortLast(arrLast, 0, size - 1);
    clock_t endLast = clock();
    double timeLast = double(endLast - startLast) / CLOCKS_PER_SEC;
    cout << "Size: " << size << ", Time (Last Element Pivot): " << timeLast << " seconds" << endl;

    // Quick Sort with random pivot
    vector<int> arrRandom = arr;
    clock_t startRandom = clock();
    quickSortRandom(arrRandom, 0, size - 1);
    clock_t endRandom = clock();
    double timeRandom = double(endRandom - startRandom) / CLOCKS_PER_SEC;
    cout << "Size: " << size << ", Time (Random Pivot): " << timeRandom << " seconds" << endl;
}

int main() {
    // Initialize random seed
    srand(time(0));

    // Measure performance for arrays of sizes 100, 1000, and 10000
    measureQuickSortPerformance(100);
    measureQuickSortPerformance(1000);
    measureQuickSortPerformance(10000);

    return 0;
}
