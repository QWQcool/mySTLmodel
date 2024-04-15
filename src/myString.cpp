#include"myString.h"

myString::myString(const char* str) {
	if (str == nullptr) {
		//std::cout << "构造函数赋值为空" << std::endl;
		m_data = new char[1];//对空字符串自动申请存放结束标志'\0'的
		m_data[0] = '\0';
		m_size = 0;
		m_capacity = 1;
	}
	else {
		//std::cout << "构造函数" << std::endl;
		m_size = strlen(str);
		m_capacity = m_size+1;
		m_data = new char[m_size + 1];
		strcpy_s(m_data,m_size+1 ,str);//我们要想对字符串进行增删查改，得先另外开辟一段空间（在堆上）
		                    //再将str指向的字符串拷贝到这段空间：
	}
}

myString::~myString() {
	delete[] m_data;
}

myString::myString(const myString& str)
	:m_data(nullptr)
{
	//m_size = strlen(str.m_data);
	//m_capacity = m_size;
	//myString tmp(str.m_data);
	//std::swap(m_data, tmp.m_data); //另一种写法
	//std::cout<< "深拷贝" << std::endl;
	m_size = strlen(str.m_data);
	m_capacity = m_size+1;
	m_data = new char[m_size + 1];
	strcpy_s(m_data, m_size+1, str.m_data);
}


myString& myString::operator=(const myString& str) {
	if (this == &str) {
		return *this;
	}
	m_size = strlen(str.m_data);
	m_capacity = m_size+1;
	//std::cout << "oper=" << std::endl;
	char* tmp = new char[m_size + 1];//先开空间再释放原空间，减少开空间失败带来的损失
	delete[] m_data;
	m_data = tmp;
	strcpy_s(m_data, m_size + 1, str.m_data);
	return *this;
}

myString myString::operator+ (const myString& str2)
{
	myString tmp;
	delete tmp.m_data;
	tmp.m_size = strlen(m_data) + strlen(str2.m_data);
	tmp.m_data = new char[tmp.m_size + 1];
	tmp.m_capacity = tmp.m_size + 1;
	strcpy_s(tmp.m_data,tmp.m_size+1 ,m_data);
	strcat_s(tmp.m_data, tmp.m_size + 1, str2.m_data); 
	return tmp;
}

myString& myString::operator+=(const myString& s) {
	// 计算新字符串的长度
	size_t newSize = strlen(this->m_data) + strlen(s.m_data) + 1;

	// 分配新的内存来存储新的字符串
	char* newStr = new char[newSize];

	// 将当前对象的字符串复制到新的内存中
	strcpy_s(newStr, newSize,this->m_data);

	// 将参数对象的字符串追加到新的字符串中
	strcat_s(newStr,newSize ,s.m_data);

	// 释放旧的内存
	delete[] this->m_data;

	// 更新当前对象的字符串和大小
	this->m_data = newStr;
	this->m_size = newSize;
	this->m_capacity = newSize + 1;

	return *this;
}


char& myString::operator[](size_t pos)
{
	assert(pos < this->m_size);
	return m_data[pos]; //等价于 *(_str+pos)
}

std::istream& operator >> (std::istream& cin, myString& str){
	const int buffSz = 10000; // 输入缓冲区大小
	char buff[buffSz];
	cin.get(buff, buffSz); // 读到换行或者缓冲区满了

	//分配内存给新string
	char* newData = new char[strlen(buff) + 1];
	strcpy_s(newData, strlen(buff) + 1,buff);

	// 清除旧内存
	if (str.m_data) {
		delete[] str.m_data;
	}

	// 更新string
	str.m_data = newData;
	str.m_size = strlen(buff);
	str.m_capacity = str.m_size + 1;

	return cin;
}

std::ostream& operator << (std::ostream& cout, myString& str) {
	cout << str.m_data ;
	return cout;
}

bool operator > (const myString& str1, const myString& str2)
{
	return strcmp(str1.m_data, str2.m_data) > 0;
}
bool operator < (const myString& str1, const myString& str2)
{
	return strcmp(str1.m_data, str2.m_data) < 0;
}
bool operator >= (const myString& str1, const myString& str2)
{
	return strcmp(str1.m_data, str2.m_data) >= 0;
}
bool operator <= (const myString& str1, const myString& str2)
{
	return strcmp(str1.m_data, str2.m_data) <= 0;
}

bool operator == (const myString& str1, const myString& str2)
{
	return strcmp(str1.m_data, str2.m_data) == 0;
}
bool operator != (const myString& str1, const myString& str2)
{
	return strcmp(str1.m_data, str2.m_data) != 0;
}


myString myString::substr(size_t pos, size_t len) const {
	// 检查 pos 是否在字符串范围内
	if (pos > m_size) {
		throw std::out_of_range("Position out of range");
	}

	// 计算实际的长度，以防 len 超出字符串的长度
	size_t actualLen = std::min(len, m_size - pos);

	// 创建一个新的 myString 对象，用于存储子串
	myString result;
	result.m_data = new char[actualLen + 1]; // 分配内存，+1 是为了存储空字符
	result.m_size = actualLen;
	result.m_capacity = m_size + 1;

	// 复制子串到新对象中
	strncpy_s(result.m_data, actualLen + 1, m_data + pos, actualLen);
	result.m_data[actualLen] = '\0'; // 确保字符串以空字符结尾

	return result;
}

void myString::reserve(size_t n) {
	if (n > this->m_capacity)
	{
		char* tmp = new char[n + 1];
		strcpy_s(tmp,n+1,this->m_data);
		delete[] this->m_data;
		this->m_capacity = n;
	//this->m_size = n ;//扩容扩的是容量
		this->m_data = tmp;
	}
}

void myString::resize(size_t n, char ch) {
	if (n < this->m_capacity) {
		this->m_data[n] = '\0';
		this->m_capacity = n;
		//this->m_size = n - 1;
	}
	else {
		if (n > this->m_capacity) {
			reserve(n);
		}
		memset(this->m_data, ch, n - this->m_size);//从_str 的 _size 处开始初始化，把n-_size个位置初始化为 ch
	}
}

void myString::checkExpend(size_t additionalSize) {
	if (this->m_size + additionalSize >= this->m_capacity) {
		this->m_capacity = this->m_capacity == 0 ? 1 : this->m_capacity;
		// 计算新的容量，确保有足够的空间来存储当前字符串和要添加的字符串
		//reserve(this->m_capacity +1); // 分配次数多但是稳定，额外的1是为了存储字符串结束符'\0'
		reserve(this->m_capacity * 2);// 增加当前容量的两倍,分配次数变少，但是可能浪费空间或者爆空间
	}
}

void myString::append(const myString& st)
{
	size_t additionalSize = strlen(st.m_data);
	checkExpend(additionalSize);
	strcat_s(this->m_data, this->m_capacity, st.m_data);
	this->m_size += additionalSize; // 更新字符串的大小
}

void myString::append(const char* s)
{
	size_t additionalSize = strlen(s);
	checkExpend(additionalSize);
	strcat_s(this->m_data, this->m_capacity, s);
	this->m_size += additionalSize; // 更新字符串的大小
}

void myString::push_back(const char ch)
{
	checkExpend(1);
	this->m_data[this->m_size] = ch;
	this->m_size++;
	this->m_data[this->m_size + 1] = '\0'; // 确保字符串以'\0'结尾
}

void myString::pop_back() {
	if (this->m_size > 0) {
		this->m_data[m_size - 1] = '\0'; // 移除最后一个字符
		this->m_size--;
	}
}

void myString::insert(char ch, size_t pos)
{
	if (pos > this->m_size) {
		throw std::out_of_range("Position out of range");
	}

	//判断是否需要增容
	checkExpend(1);

	int end = this->m_size;
	while (end >= pos)
	{
		this->m_data[end + 1] = this->m_data[end];
		end--;
	}
	this->m_data[pos] = ch;
	this->m_size++;
	this->m_data[this->m_size + 1] = '\0';
}

void myString::insert(const char* s, size_t pos) {
	if (pos > this->m_size) {
		throw std::out_of_range("Position out of range");
	}
		int len = strlen(s);
		//判断是否需要增容
		checkExpend(len);

		int end = this->m_size;
		while (end >= pos)
		{
			this->m_data[end + len] = this->m_data[end];       //把每个字符向后移动len位
			end--;
		}

		for (size_t i = 0; i < len; i++)
		{
			this->m_data[pos + i] = s[i];              //把 s 中的每个字符逐个放到空出来的位置
		}
		this->m_size += len;
		this->m_data[this->m_size + 1] = '\0';
}

//还可以用kmp算法实现find函数，过于复杂遂放弃
size_t myString::find(const char* s, size_t index)
{
	size_t length = strlen(s);
	for (size_t this_index = index; this_index < this->m_size; this_index++)
	{
		if (this->m_data[this_index] == s[0])
		{
			for (int s_index = 0; s_index < length; s_index++)
			{
				if (this->m_data[this_index + s_index] != s[s_index])
					break;
				if (s_index == length - 1)  //匹配字符串
					return this_index;
			}
		}
	}
	return -1;
}

size_t myString::find(const myString& st, size_t index)
{
	size_t length = strlen(st.m_data);
	for (size_t this_index = index; this_index < this->m_size; this_index++)
	{
		if (this->m_data[this_index] == st.m_data[0])
		{
			for (int s_index = 0; s_index < length; s_index++)
			{
				if (this->m_data[this_index + s_index] != st.m_data[s_index])
					break;
				if (s_index == length - 1)  //匹配字符串
					return this_index;
			}
		}
	}
	return -1;
}

size_t myString::find(const char ch, size_t index)
{
	size_t length = 1;
	for (size_t this_index = index; this_index < this->m_size; this_index++)
	{
		if (this->m_data[this_index] == ch)
		{
					return this_index;
		}
	}
	return -1;
}

void myString::showString() {
	std::cout << this->m_data << std::endl;
}
