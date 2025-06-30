#include<stdio.h>
#include<iostream>
using namespace std;

int main (void){
    cout << "Enter a char: ";
    char ch1;
    // cin>> ch;
    ch1 = cin.get();

    cout << static_cast<int>(ch1)<<endl;
    

     cout << "Enter a char: ";
     cin.ignore();
    char ch2;
    // cin>> ch;
    ch2 = cin.get();

    cout << static_cast<int>(ch2)<<endl;


    return 0;

}