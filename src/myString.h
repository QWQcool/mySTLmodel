#pragma once
//#define _CRT_SECURE_NO_WARNINGS   if  use unsafe cstring function
#include<iostream>
#include <cstring>
#include<cassert>

class myString {
public:
	/*--------------basic-------------------*/
	myString(const char* str = nullptr);
	myString(const myString& str);  //���
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
	myString& operator=(const myString& str);//���� = ���������������Ϊ��֧��������ֵ����������C++�����壬���ҿ����������
	myString operator+(const myString& str);//����ĺ�����Ҫ����һ���¶���ʱ��Ӧ�÷��ض��������������
	myString& operator+=(const myString& str);
	char& operator[](size_t pos);//ʵ��������ʵ����������
	friend std::istream& operator >> (std::istream& cin, myString& str);   // ���룬��������������
	friend std::ostream& operator << (std::ostream& cout, myString& str);

	friend bool operator > (const myString& str1, const myString& str2);  // ����Ƚ�����
	friend bool operator < (const myString& str1, const myString& str2);
	friend bool operator >= (const myString& str1, const myString& str2);
	friend bool operator <= (const myString& str1, const myString& str2);
	friend bool operator == (const myString& str1, const myString& str2);
	friend bool operator != (const myString& str1, const myString& str2);
	

	/*---------------function------------*/
	myString substr(size_t pos, size_t len) const;  ////���Ӵ�����
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

/* C++������֮String���ʵ�� https://blog.csdn.net/caoshangpa/article/details/51530482 */
/* ��дһ��String�ࣨc++ʵ�� https://blog.csdn.net/qq_40821469/article/details/108913326 */
/* C++�Լ�ʵ��һ��String�� https://zhuanlan.zhihu.com/p/62290636 */
/* C++ String������ https://zhuanlan.zhihu.com/p/585153125 */
/* ��C++���ְ��ֽ���д�����Լ���String��  https://blog.csdn.net/qq_53268869/article/details/121528154 */
