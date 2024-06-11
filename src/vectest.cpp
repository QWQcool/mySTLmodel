#include<iostream>
#include "myVector.h"


int main()
{
    Int_Vector v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    auto begin = v.begin();
    auto end = v.end();
    std::cout <<"iterator:" << std::endl;
    std::cout << *(begin + 2) << std::endl;
    //for (;begin != end; ++begin)
    //{
    //std::cout << *begin << " " << std::endl;
    //}
    return 0;
}