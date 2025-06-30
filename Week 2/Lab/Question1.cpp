#include <iostream>
#include <string>

using namespace std;
int main (void){
    string name;
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Welcome, " << name << endl;
    return 0;
}