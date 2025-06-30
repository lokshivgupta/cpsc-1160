#ifndef TEXT_H
#define TEXT_H
#include<string>
using namespace std;

class Text {
    public:
        Text(); //default constructor 
        Text(string); // param cknstructor
        Text(const Text&); 

        void append(const Text&);
        unsigned int getLength() const;
        void clear();
        bool deleteFirst(char);

        ~Text(); //destructor


        unsigned int getId();
        Text operator+(const Text&) const;
        Text& operator=(const Text&);
        char& operator[](int);
        

    private:
        void expand(unsigned int);
        char* s;
        unsigned leng;
        unsigned cap;
        unsigned int id;
        static unsigned int nextId;
        

};
#endif