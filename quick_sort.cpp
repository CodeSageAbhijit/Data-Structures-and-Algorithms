#include <iostream>
using namespace std;



int partition(int array[],int lower_bound,int upper_bound){
    int pivot = array[lower_bound];
    int start = lower_bound;
    int end = upper_bound;
    while(start<=end){
        while(array[start] <= pivot){
            start++;
        }
        while(array[end] > pivot){
            end--;
        }
        if(start<=end){
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    
    int temp = array[lower_bound];
    array[lower_bound] = array[end];
    array[end] = temp;
    return end;
}

void quicksort(int array[],int lower_bound,int upper_bound){
    if (lower_bound < upper_bound){
        int location = partition(array,lower_bound,upper_bound);
        quicksort(array,lower_bound,location-1);
        quicksort(array,location+1,upper_bound);
    }
}


int main(void){
    int array[] = {7,4,10,8,3,1};
    int size = sizeof(array)/sizeof(array[0]);
    int lower_bound = 0;
    int upper_bound = size - 1;

    quicksort(array,lower_bound,upper_bound);

    for(int i=0;i<size;i++){
        cout << array[i] << " ";
    }

    return 0;
    
}