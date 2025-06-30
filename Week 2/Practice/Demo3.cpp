#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main (void){
    cout<<"Enter your full name";
    string userName;
    getline(cin,userName), '#';
    cout <<"Your name is " << userName <<endl;

    return 0;

}