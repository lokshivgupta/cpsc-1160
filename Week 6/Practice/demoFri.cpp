#include<iostream>
#include "List.h"
using namespace std;

template <typename T>
int linearSearch(const T* list, unsigned size, T key){
    for(int i = 0; i< size; ++i){
        if(list [i] == key){
            return i;
        }else{
            return -1;
        }
    }
}
template <typename T1, typename T2>
void printThem(T1 v1, T2 v2){
    cout << v1 <, v2<<endl;
}


//This fails
template <typename T>
void printThem(T v1, T v2){
    cout << v1 <, v2<<endl;
}


int main (){
    printThem(5.0,10);
    int myList[] =  { 1,2,8,9,3};
    int key = 44;
    cout << linearSearch(myList,5,key);
    List<double> grades;
    List<char> initials;
    List<double> gpas;
    List<>integers;
}