#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H
#include <string>
#include<cctype>
#include<cstdlib>
using namespace std;

string reverse(string str){
    string reversedString = "";
    for(int i =str.length()-1; i >= 0;i--){
        reversedString += str[i];
    }
    return reversedString;
}

string capitalization(string &str){
    for(int i =0; i < str.length(); i++){
        char ch = str[i];
        if(ch >= 'a' && ch<= 'z'){
            str.at(i) = ch - ('a' - 'A');
        }
    }
}

void findMinMax(int arr[], int size, int &min, int &max){
    int min = arr[0];
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if (arr[i] > max){
            max = arr[i];
        }
    }
}

void capitalizeArrayString(string arr[], int size){
    for(int i=0; i < size; i++){
        capitalization(arr[i]);
    }
}

bool areEqual(const int matrix [][10], const int col, const int row){
    for(int i =0; i < col; i++){
        if(matrix[0][i]!=matrix[row - 1][i]){
            return false;
        }
       
    }
     return true;
}

void shuffleArray(const int input[], int output [], int size){
    for (int i = 0; i < size; i++){
        output[i] = input[i];
    }
    for(int i =0; i < size; i++){
        int j = rand() % (i+1);
        int temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}


#endif