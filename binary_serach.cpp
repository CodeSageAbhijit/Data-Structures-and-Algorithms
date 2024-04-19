#include <iostream>
#include <cmath>
using namespace std;

int binary_search(int array[],int size,int key){
    int left=0;
    int right = size-1;

    while (left <= right){
        int mid = floor((left+right)/2);
        if (key==array[mid]) return mid;
        else if (key < array[mid]) right=mid-1;
        else left=mid+1;
    }


    return -1;
}


int main(void){
    int array[] = {1,4,9,16,25,36,49,64,81,100};
    int size = sizeof(array)/sizeof(array[0]);
    int key = 100;

    int binary_search_result = binary_search(array,size,key);
    // cout << binary_search_result;
    if (binary_search_result != -1){
        cout << "key found at index:" << binary_search_result;
    }
    else{
        cout << "key not found";
    }


}