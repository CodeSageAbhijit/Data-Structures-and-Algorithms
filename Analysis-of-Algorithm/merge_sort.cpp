#include <iostream>
using namespace std;



void merge(int array[], int lower_bound, int mid, int upper_bound) {
    int i = lower_bound;
    int j = mid + 1;
    int k = 0; // Index for sorted_array
    int sorted_array[upper_bound - lower_bound + 1];

    while (i <= mid && j <= upper_bound) {
        if (array[i] <= array[j]) {
            sorted_array[k] = array[i];
            k++;
            i++;

        } else {
            sorted_array[k] = array[j];
            k++;
            j++;
        }
    }
    
    // Copy remaining elements from the first subarray
    while (i <= mid) {
        sorted_array[k] = array[i];
        k++;
        i++;
    }

    // Copy remaining elements from the second subarray
    while (j <= upper_bound) {
        sorted_array[k] = array[j];
        k++;
        j++;
    }

    // Copy the sorted subarray back to the original array
    for (int x = lower_bound; x <= upper_bound; x++) {
        array[x] = sorted_array[x - lower_bound];
    }
}


void mergesort(int array[],int lower_bound,int upper_bound){
        if (lower_bound < upper_bound){
            int mid = (lower_bound + upper_bound) / 2;
            mergesort(array,lower_bound,mid);
            mergesort(array,mid+1,upper_bound);
            merge(array,lower_bound,mid,upper_bound);
        }
    }


int main(){

    int array[] = {7,4,0,2,6,9,2,8,1,5,3};
    int lower_bound = 0;
    int upper_bound = sizeof(array) / sizeof(array[0]) - 1;


    mergesort(array,lower_bound,upper_bound);

    // Printing sorted array
    for (int i = 0; i <= upper_bound; i++) {
        cout << array[i] << " ";
    }
    cout << endl;


    return 0;
}
