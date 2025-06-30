#include<iostream>
using namespace std;
class Rectangle{
public:
    Rectangle(){
        width = 1;
        length = 1 ;
    }
    Rectangle(double w, double l){
        if(w > 0){
           this -> width = w;
        }else{
            width = 1;
        }
       if(l > 0){
        this -> length = l;
       }else{
        this-> length = 1;
       }
        
    }
    double getArea(){
        return width * length;
    }
    double getPerm(){
        return 2 *(width + length);
    }
    double getWidth(){
        return width;
    }
    void setWidth(double val){
        if(val > 0){
            width = val;
        }
    }
    void setLength(double leng){
        if(leng > 0){
            length = leng;
        }
    }
    double getLength(){
        return length;
    }
private:
    double length, width;

};

//write a program that reads the width and the lenght of a rectangle from the keyboard, creates a rectagle object of that size in the 
//memory and cal the area and the permineter of the rectangle
int main(){
    cout << "Enter the wid and length of the rectangle " <<endl;
    double w,l;
    cin >> w >> l;
   // Rectangle r; // this calls a default constructor
    // r.width = w;
    // r.length = l; // direct access to it

    Rectangle rect (w,l);
    rect.setLength(l);
    rect.setWidth(w);

    // Rectangle *p; //ponter, no constructor 8byte on the stack
    // Rectangle r ; // defualt constructor stack
    // p = &r;
    // (*p).setLength(56);
    // p = new Rectangle(2,3); //we are creating a new object(anonymous object), pointer is pointing to it
    // delete p;
    // (*p).setWidth(67);// logic error

    // Rectangle a[10]; // default constructor is called 10 times, locted on stack
    // a[0].setLength(2);


    cout <<"Area is " << rect.getArea() << endl;
    cout <<"PErmeter is " << rect.getPerm() << endl;
    return 0;

}