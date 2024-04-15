#include"myString.h"

myString::myString(const char* str) {
	if (str == nullptr) {
		//std::cout << "���캯����ֵΪ��" << std::endl;
		m_data = new char[1];//�Կ��ַ����Զ������Ž�����־'\0'��
		m_data[0] = '\0';
		m_size = 0;
		m_capacity = 1;
	}
	else {
		//std::cout << "���캯��" << std::endl;
		m_size = strlen(str);
		m_capacity = m_size+1;
		m_data = new char[m_size + 1];
		strcpy_s(m_data,m_size+1 ,str);//����Ҫ����ַ���������ɾ��ģ��������⿪��һ�οռ䣨�ڶ��ϣ�
		                    //�ٽ�strָ����ַ�����������οռ䣺
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
	//std::swap(m_data, tmp.m_data); //��һ��д��
	//std::cout<< "���" << std::endl;
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
	char* tmp = new char[m_size + 1];//�ȿ��ռ����ͷ�ԭ�ռ䣬���ٿ��ռ�ʧ�ܴ�������ʧ
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
	// �������ַ����ĳ���
	size_t newSize = strlen(this->m_data) + strlen(s.m_data) + 1;

	// �����µ��ڴ����洢�µ��ַ���
	char* newStr = new char[newSize];

	// ����ǰ������ַ������Ƶ��µ��ڴ���
	strcpy_s(newStr, newSize,this->m_data);

	// ������������ַ���׷�ӵ��µ��ַ�����
	strcat_s(newStr,newSize ,s.m_data);

	// �ͷžɵ��ڴ�
	delete[] this->m_data;

	// ���µ�ǰ������ַ����ʹ�С
	this->m_data = newStr;
	this->m_size = newSize;
	this->m_capacity = newSize + 1;

	return *this;
}


char& myString::operator[](size_t pos)
{
	assert(pos < this->m_size);
	return m_data[pos]; //�ȼ��� *(_str+pos)
}

std::istream& operator >> (std::istream& cin, myString& str){
	const int buffSz = 10000; // ���뻺������С
	char buff[buffSz];
	cin.get(buff, buffSz); // �������л��߻���������

	//�����ڴ����string
	char* newData = new char[strlen(buff) + 1];
	strcpy_s(newData, strlen(buff) + 1,buff);

	// ������ڴ�
	if (str.m_data) {
		delete[] str.m_data;
	}

	// ����string
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
	// ��� pos �Ƿ����ַ�����Χ��
	if (pos > m_size) {
		throw std::out_of_range("Position out of range");
	}

	// ����ʵ�ʵĳ��ȣ��Է� len �����ַ����ĳ���
	size_t actualLen = std::min(len, m_size - pos);

	// ����һ���µ� myString �������ڴ洢�Ӵ�
	myString result;
	result.m_data = new char[actualLen + 1]; // �����ڴ棬+1 ��Ϊ�˴洢���ַ�
	result.m_size = actualLen;
	result.m_capacity = m_size + 1;

	// �����Ӵ����¶�����
	strncpy_s(result.m_data, actualLen + 1, m_data + pos, actualLen);
	result.m_data[actualLen] = '\0'; // ȷ���ַ����Կ��ַ���β

	return result;
}

void myString::reserve(size_t n) {
	if (n > this->m_capacity)
	{
		char* tmp = new char[n + 1];
		strcpy_s(tmp,n+1,this->m_data);
		delete[] this->m_data;
		this->m_capacity = n;
	//this->m_size = n ;//��������������
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
		memset(this->m_data, ch, n - this->m_size);//��_str �� _size ����ʼ��ʼ������n-_size��λ�ó�ʼ��Ϊ ch
	}
}

void myString::checkExpend(size_t additionalSize) {
	if (this->m_size + additionalSize >= this->m_capacity) {
		this->m_capacity = this->m_capacity == 0 ? 1 : this->m_capacity;
		// �����µ�������ȷ�����㹻�Ŀռ����洢��ǰ�ַ�����Ҫ��ӵ��ַ���
		//reserve(this->m_capacity +1); // ��������൫���ȶ��������1��Ϊ�˴洢�ַ���������'\0'
		reserve(this->m_capacity * 2);// ���ӵ�ǰ����������,����������٣����ǿ����˷ѿռ���߱��ռ�
	}
}

void myString::append(const myString& st)
{
	size_t additionalSize = strlen(st.m_data);
	checkExpend(additionalSize);
	strcat_s(this->m_data, this->m_capacity, st.m_data);
	this->m_size += additionalSize; // �����ַ����Ĵ�С
}

void myString::append(const char* s)
{
	size_t additionalSize = strlen(s);
	checkExpend(additionalSize);
	strcat_s(this->m_data, this->m_capacity, s);
	this->m_size += additionalSize; // �����ַ����Ĵ�С
}

void myString::push_back(const char ch)
{
	checkExpend(1);
	this->m_data[this->m_size] = ch;
	this->m_size++;
	this->m_data[this->m_size + 1] = '\0'; // ȷ���ַ�����'\0'��β
}

void myString::pop_back() {
	if (this->m_size > 0) {
		this->m_data[m_size - 1] = '\0'; // �Ƴ����һ���ַ�
		this->m_size--;
	}
}

void myString::insert(char ch, size_t pos)
{
	if (pos > this->m_size) {
		throw std::out_of_range("Position out of range");
	}

	//�ж��Ƿ���Ҫ����
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
		//�ж��Ƿ���Ҫ����
		checkExpend(len);

		int end = this->m_size;
		while (end >= pos)
		{
			this->m_data[end + len] = this->m_data[end];       //��ÿ���ַ�����ƶ�lenλ
			end--;
		}

		for (size_t i = 0; i < len; i++)
		{
			this->m_data[pos + i] = s[i];              //�� s �е�ÿ���ַ�����ŵ��ճ�����λ��
		}
		this->m_size += len;
		this->m_data[this->m_size + 1] = '\0';
}

//��������kmp�㷨ʵ��find���������ڸ��������
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
				if (s_index == length - 1)  //ƥ���ַ���
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
				if (s_index == length - 1)  //ƥ���ַ���
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
