#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


int main (){
    srand(time(0));
    int random = rand() % 29 + 2;

    cout << "Random Number: "<< random << endl;

    for(int i = 1; i <= random; i++){
        for(int j = 0; j< i; j++){
            cout << "*";
        }
       cout  << endl;
    }

    return 0;
}