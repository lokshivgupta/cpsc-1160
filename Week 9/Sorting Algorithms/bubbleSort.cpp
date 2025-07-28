#include<iostream>
using namespace std;

void bubbleSort(int list[], int size){
    bool toContinu = true;
    for(unsigned int i = 1; toContinu&& i < size; i++){
        toContinu = false;
        for(unsigned int j = 0; j <= size - 1 - i;j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;

                toContinu = true;
            }
        }
    }
}