#include <iostream>
#include <string>

using namespace std;

int main (void){
 int a = 5, b = 1;
int c = a++;
cout << --b;
cout << a;
cout << b;
cout << c++; 
cout << c;
a = b + c++;
cout << a;
}
