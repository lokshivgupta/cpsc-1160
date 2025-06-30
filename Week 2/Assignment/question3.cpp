#include<iostream>
using namespace std;

int main (){
    int number;
    cout << "Enter a number: ";
    cin >> number;

    number ^= (1<<0);
    number ^= (1<< 10);
    
    number |= (1<<1);
    number |= (1<<3);
    number |= (1<<30);

    number &= ~(1<<12);
    number &= ~(1<<20);

    cout << "After change: " << number << endl;
}
