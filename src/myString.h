#pragma once
//#define _CRT_SECURE_NO_WARNINGS   if  use unsafe cstring function
#include<iostream>
#include <cstring>
#include<cassert>

class myString {
public:
	/*--------------basic-------------------*/
	myString(const char* str = nullptr);
	myString(const myString& str);  //深拷贝
	~myString();
	size_t length() const { return m_size; }
	size_t _index() const { return m_size; }
	size_t capacity() const { return m_capacity; }
	const char* c_str()const { return m_data; }
	char* begin() { return m_data; }
	char* end() { return m_data + m_size; }
	const char* begin() const { return m_data; }
	const char* end() const { return m_data + m_size; }

    /*--------------operator--------------*/
	myString& operator=(const myString& str);//重载 = 运算符返回引用是为了支持连续赋值操作，符合C++的语义，并且可以提高性能
	myString operator+(const myString& str);//当你的函数需要返回一个新对象时，应该返回对象本身而不是引用
	myString& operator+=(const myString& str);
	char& operator[](size_t pos);//实现数组访问的运算符重载
	friend std::istream& operator >> (std::istream& cin, myString& str);   // 输入，输出运算符的重载
	friend std::ostream& operator << (std::ostream& cout, myString& str);

	friend bool operator > (const myString& str1, const myString& str2);  // 各类比较重载
	friend bool operator < (const myString& str1, const myString& str2);
	friend bool operator >= (const myString& str1, const myString& str2);
	friend bool operator <= (const myString& str1, const myString& str2);
	friend bool operator == (const myString& str1, const myString& str2);
	friend bool operator != (const myString& str1, const myString& str2);
	

	/*---------------function------------*/
	myString substr(size_t pos, size_t len) const;  ////求子串函数
	void reserve(size_t n);
	void resize(size_t n, char ch);
	void checkExpend(size_t additionalSize);
	void append(const myString& str);
	void append(const char* s);
	void push_back(const char s);
	void pop_back();
	void insert(const char ch, size_t pos);
	void insert(const char* s, size_t pos);
	size_t find(const char* s, size_t index = 0);
	size_t find(const myString& str, size_t index = 0);
	size_t find(const char ch, size_t index = 0);
	void showString();
private:
	char* m_data;
	size_t m_size;
	size_t m_capacity;
	//static const size_t npos;
};

/* C++笔试题之String类的实现 https://blog.csdn.net/caoshangpa/article/details/51530482 */
/* 编写一个String类（c++实现 https://blog.csdn.net/qq_40821469/article/details/108913326 */
/* C++自己实现一个String类 https://zhuanlan.zhihu.com/p/62290636 */
/* C++ String类的详解 https://zhuanlan.zhihu.com/p/585153125 */
/* 【C++】手把手教你写出你自己的String类  https://blog.csdn.net/qq_53268869/article/details/121528154 */
