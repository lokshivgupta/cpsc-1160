#include<iostream>
using namespace std;

void merge(const int arr1[],const int arr2[], const int size1,const int size2, int result[]){
    int i = 0, j = 0, k = 0;
    while(i < size1 && j < size2){
        if(arr1[i] < arr2[j]){
            result[k++]  = arr1[i++];
        }else{
            result[k++] = arr2[j++];
        }
    }

    while(i < size1){
        result[k++] = arr1[i++];
    }
    while(j < size2){
        result[k++] = arr2[j++];
    }
}

void copy(const int list[], int startIndex, int copy[], int size){
    for(int i = startIndex; i < size; i++){
        copy[i- startIndex] = list[i];
    }

}


void mergeSort(int list[], int size){
    if(size > 1){
        int *firstHalf = new int[size/2];
        copy(list,0,firstHalf,size/2);
        mergeSort(firstHalf,size/2);

        int *secondHalf = new int[size - size/2];
         copy(list,size/2,secondHalf,size - size/2);
         mergeSort(secondHalf,size- size/2);

         merge(firstHalf,secondHalf,size/2,size-size/2,list);

         delete[] firstHalf;
         delete [] secondHalf;
    }
    
}