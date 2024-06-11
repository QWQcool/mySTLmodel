#include<iostream>
#include "myString.h"


int main()
{
    myString str = "Hello";
    myString str1 = "Hello";
    str += "World";
    str += str1;
    str = str + str1;
    str[9] = 'a';
    const char* C_Str1 = str1.c_str();
    int Str_Length =str.length();
    int Str_Size = str._index();
    int Find_Pos = str.find("Hello");
    std::cout << "C_Str:"<<C_Str1 << " Str_Length:" << Str_Length << " Str_Size:" << Str_Size <<" Find_Pos:" << Find_Pos << std::endl;
    std::cout << "str:" << str << std::endl;
    return 0;
}