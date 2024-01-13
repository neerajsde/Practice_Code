#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

class MyString{
    char *data;
    size_t length;
public:
    // Default constructor
    MyString();

    // Parameterized  constructor
    MyString(const char *data);

    // Copy constructor
    MyString(const MyString &other);

    // dtor
    ~MyString();

    // Print String
    void Print();

    // size of string
    size_t size();

    // Subscript ([]) operator
    char operator[](size_t index);

    // Find substr
    int find_substr(MyString &substring);

    // push_back insert char into at last Index
    void push_back(const char &ch);

    // pop_back delete char from last/end
    void pop_back();

    // INSERT AT INDEX
    void insert(const char* str_, int index, int length);
};

#endif