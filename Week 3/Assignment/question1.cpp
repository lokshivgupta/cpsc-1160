#include<iostream>
using namespace std;

int main (){
    int num, temp;
    int reversedNum = 0;
    bool isNegative;
    cout<< "Enter an integer: " <<endl;
    cin >> num;
    if (num <0){
        isNegative = true;
        num = abs(num);
    }else {
        isNegative = false;
    }
    while(num != 0){
        temp = num % 10;
        reversedNum = reversedNum * 10 + temp;
        num = num/10;
    }

    if(isNegative){
        reversedNum = -reversedNum;
    }
    cout << "Reversed number: "<<reversedNum <<endl;

    return 0;
}