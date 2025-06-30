
// This simple example is to teach you the concept of aggregation and the order in which the constructor 
// and destructors are called When we have aggregated types (objects).

#include <iostream>
using namespace std;

class Member1{
public:
    Member1(){cout << "member1 was created." << endl;}
    ~Member1(){
        cout << "Member1 was destructed." << endl;
    }
};

class Member2{
public:
    Member2 (){
        cout << "member2 was created." << endl;
    }
    Member2(int){cout << "member2 was created." << endl;}
    ~Member2(){
        cout << "Member2 was destructed." << endl;
    }
};


class Container{
public:
    Container(){
        cout << "Container was created" << endl;
    }

    ~Container(){
        cout << "Container was destructed." << endl;
    }

private:
    Member1 m1;
    Member2 m2;
};

int main(){
    Container x;
    
    return 0;
}

