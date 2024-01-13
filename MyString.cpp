#include "MyString.h"
#include <cstring> // for strcpy, strlen, etc..
#include <iostream>

// Default constructor
MyString::MyString(){
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// Parameterized constructor
MyString::MyString(const char *str){
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}

// COPY CONSTRUCTOR
MyString::MyString(const MyString &other){
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);
}

// dtro
MyString::~MyString(){
    delete[] data;
}

// Printing String
void MyString::Print(){
    for(int i=0; i<length; i++){
        std::cout << data[i];
    }
    std::cout << std::endl;
}

// Size of string
size_t MyString::size(){
    return length;
}

// Subscript ([]) operator
char MyString::operator[](size_t index)
{
    if (index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

int MyString::find_substr(MyString &substring){
    if(length < substring.length){
        return -1;
    }
    for(int i=0; i<=(length - substring.length); i++){
        size_t j;
        for(j=0; j<substring.length; j++){
            if(data[i + j] != substring.data[j]){
                break;
            }
        }
        if(j == substring.length){
            return i;
        }
    }
    return -1;
}

void MyString::push_back(const char &ch){
    char *old_str = new char[length];
    for(int i=0; i<length; i++){
        old_str[i] = data[i];
    }
    data = new char[length + 1];
    int i;
    for(i=0; i<length; i++){
        data[i] = old_str[i];
    }
    data[i] = ch;
    length++;
    delete old_str;
}

void MyString::pop_back(){
    char *old_str = new char[length];
    for(int i=0; i<length; i++){
        old_str[i] = data[i];
    }
    data = new char[length - 1];
    for(int i=0; i<length-1; i++){
        data[i] = old_str[i];
    }
    length--;
    delete old_str;
}

void MyString::insert(const char* str_, int index, int str_len){
    char* old_str = new char[length];
    char* str = new char[str_len];
    strcpy(str, str_);
    for(int i=0; i<length; i++){
        old_str[i] = data[i];
    }
    data = new char[length+str_len];
    int i=0;
    while(i<index){
        data[i] = old_str[i];
        i++;
    }
    int j=0; int k = i;
    while(j<str_len){
        data[i] = str[j];
        j++;i++;
    }
    while(i<length+str_len){
        data[i] = old_str[k];
        i++; k++;
    }
    length += str_len;
    delete old_str;
}