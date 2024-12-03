#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // Set pivot as the first element
    int i = low + 1;       // Start i from the element next to the pivot

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]); // Move pivot to its correct position
    return i - 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    cout << "ORIGINAL ARRAY: ";
    printArray(arr);

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    cout << "SORTED ARRAY: ";
    printArray(arr);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "TIME TAKEN BY QUICK SORT: " << time_taken << " SECONDS" << endl;

    return 0;
}
