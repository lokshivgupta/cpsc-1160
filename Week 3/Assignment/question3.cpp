#include<iostream>
#include<string>
using namespace std;

int main(){
    string inputString;
    int n;
    char ch;

    cout << "Enter a string: " << endl;
    getline(cin,inputString);

    cout << "Enter the n value: "<< endl;
    cin >> n;

     if(n<=0){
        cout << "No lookup required" <<endl;
        return 0;
    }
    cout <<"Enter the char: " << endl;
    cin >> ch;

    for(int i =0; i < inputString.length() - n; i++){
        bool match = true;

        for(int j = 0; j < n; j++){
            if(inputString[i+j] != ch){
                match = false;
                break;
            }
        }
        if(match){
            cout << "Found the char at index: " << i << endl;
            return 0;
        }
    }
    cout << "Not Found" << endl;

    return 0;
}

