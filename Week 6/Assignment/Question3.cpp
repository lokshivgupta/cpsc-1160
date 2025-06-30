#include<iostream>
using namespace std;

double* resize(double* &p, int initialSize, int newSize);

int main(){
    return 0;
}

double* resize(double* &p, int initialSize, int newSize){
    if(initialSize == newSize){
        return p;
    }

    double* newArray = new double[newSize];

    if(initialSize < newSize){
        for(int i = 0; i < newSize; i++){
            newArray[i] = p[i];
        }
        for(int i = initialSize; i < newSize; i++){
            newArray[i] = 0;
        }
    }else{
        for(int i = 0; i < newSize; i++){
            newArray[i] = p[i];
        }
    }

    delete[]p;
    p = newArray;
    return p;

    //"p" has been passed by as a reference because we had not done that then the pointer would have pointed locally to the newly allocated array
    // it would not have pointed to it outsode the function, to make it point to the newly one we had pass the reference