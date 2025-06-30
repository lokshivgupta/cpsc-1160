#ifndef LIST_H
#define LIST_H
template<typename T = int>
class List{
public:
    List();
private:
    T list[100];
    unsigned int size;
};
template <>
class List<char>{

}


#include "List.cpp.h";
#endif