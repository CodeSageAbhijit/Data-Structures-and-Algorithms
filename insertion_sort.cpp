#include <iostream>
using namespace std;

int main(void){
    int array[] = {8,76,34,123,97,1,2,3,4};
    int size = sizeof(array)/sizeof(array[0]); 

    for(int i=1;i<size;i++){
        int temp = array[i];
        int j = i-1;
        while (j>=0 and array[j] > temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }

    for(int i=0;i<size;i++){
        cout << array[i] << " ";
    }
}