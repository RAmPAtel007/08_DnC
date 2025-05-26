#include <iostream>
using namespace std;

// Partition function returns the pivot index
int partition(int arr[], int start, int end) {
    int pivot = end;
    int i = start - 1;

    for (int j = start; j < pivot; j++) {
        if (arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[pivot]);
    return i; // return pivot index
}

// QuickSort function
void QuickSort(int arr[], int s, int e) {
    if (s >= e) return;

    int p = partition(arr, s, e);  // partition and get pivot index

    QuickSort(arr, s, p - 1); // left side
    QuickSort(arr, p + 1, e); // right side
}

int main() {
    int arr[] = {8, 2, 3, 45, 75, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
