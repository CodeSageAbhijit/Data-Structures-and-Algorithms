#include <iostream>
using namespace std;

int main(void){
    int array[] = {7,4,10,8,3,1};
    int size = sizeof(array)/sizeof(array[0]);

    for(int i=0;i<size-1;i++){
        int min = i;
        for(int j=i+1;j<size;j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        if(min!=i){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }

    for(int i=0;i<size;i++){
        cout << array[i] <<endl ;
    }
}