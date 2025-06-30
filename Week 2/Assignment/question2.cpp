#include<iostream>
using namespace std;

int main (void){
    int num, power;
     cout << "Enter the number: ";
     cin >> num;
     cout << "Enter the power it needs to be raised to: ";
     cin >> power;

    int result = num << power;

    cout << "Result of " << num << " raised to the power of " << power << " = " << result;
}