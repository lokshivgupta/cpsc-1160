#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main (){
    srand(time(0));

    int a = (rand () % 256) - 128;
    int b = (rand () % 256) - 128;
    int c = (rand () % 256) - 128;
    int d = (rand () % 256) - 128;

    cout << "Random numbers: " << a << " " << b << " " << c << " " << d << endl;

    int result = d << 24 | c << 16 | b << 8 | a;

    cout << "The four-byte output (hex): 0x" << hex << result << endl;
    cout << "The four-byte output (decimal): " << dec << result << endl;

}



