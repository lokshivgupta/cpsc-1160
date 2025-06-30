#include<iostream>
using namespace std;
class Rectangle{
public:
    Rectangle();
    Rectangle(double w, double l);
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
    void setLength(double leng);

    double getLength(){
        return length;
    }
private:
    double length, width;

};


        if(leng > 0){
            length = leng;
        }
    }

    {
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