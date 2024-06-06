#include<iostream>
#include "myString.h"
#include "myList.h"
#include "myVector.h"

//动态数组在myVector.h里
//双链表在MyList.h里
//String 在MyString.h里

int main()
{
    Int_Vector v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
        std::cout << v[i] << " ";
        if (i == 9)printf("\n");
    }
    v.operator[](9) = 333;
    v.erase(9);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << v[i] << " ";
        if (i == 9)printf("\n");
    }
    Int_Vector v1(v);

    v1[9] = 9;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << v1[i] << " ";
        if (i == 9)printf("\n");
    }

    myString str = "Hello";
    myString str1 = "Hello";
    str += "World";
    str += str1;
    str = str + str1;
    str[9] = 'a';
    const char* C_Str1 = str1.c_str();
    int Str_Length =str.length();
    int Str_Size = str.size();
    int Find_Pos = str.find("Hello");
    std::cout << "C_Str:"<<C_Str1 << " Str_Length:" << Str_Length << " Str_Size:" << Str_Size <<" Find_Pos:" << Find_Pos << std::endl;
    std::cout << "str:" << str << std::endl;

    Int_Double_List DL;
    for (int i = 0; i < 10; i++)
    {
        DL.Tail_Insert(i);
    }
    std::cout << "DL.Print:";
    DL.Print();
    return 0;
}