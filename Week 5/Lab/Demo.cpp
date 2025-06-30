#include<iostream>
#include<>
using namespace std;

int linearSearch(int list[], int size, int key) {
    for(int i = 0; i < size; i++){
        if(list[i]== key){
            return i;
        }
        return -1;
    }
}

int main(){
    int a[] = {1,4,2,6,9,3,8};
    cout << linearSearch(a, 7, 9) << endl;
}

//Write a program that returns the summation of matrix
double sumMatrix(double matrix[][10], int rows, int cols){
    double s = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            s += matrix[i][j];
        }
    }
    return s;
}

//Define a function that generates n raandom integers in the tange a and b and returns the integers to the caller
void generateRandomList(int randomIntegers[], int n, int a, int b){
    srand(time(0));
    for(int i =0; i < n; i++){
        randomIntegers[i] = rand() % (b -a +1) + a;
    }
}