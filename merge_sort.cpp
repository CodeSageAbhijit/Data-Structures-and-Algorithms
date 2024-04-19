#include <iostream>
using namespace std;

void merge(int array[], int lower_bound, int mid, int upper_bound) {
    int i = lower_bound;
    int j = mid + 1;
    int k = lower_bound;
    int temp[upper_bound - lower_bound + 1]; // Corrected size of temporary array

    while (i <= mid || j <= upper_bound) { // Changed && to ||
        if (i <= mid && (j > upper_bound || array[i] <= array[j])) { // Updated condition
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    for (int l = lower_bound; l <= upper_bound; l++) { // Copy elements from temporary array to original array
        array[l] = temp[l];
    }
}

void mergesort(int array[], int lower_bound, int upper_bound) {
    if (lower_bound < upper_bound) {
        int mid = (lower_bound + upper_bound) / 2;
        mergesort(array, lower_bound, mid);
        mergesort(array, mid + 1, upper_bound);
        merge(array, lower_bound, mid, upper_bound);
    }
}

int main() {
    int array[] = {7, 4, 10, 8, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int lower_bound = 0;
    int upper_bound = size - 1;

    mergesort(array, lower_bound, upper_bound);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
