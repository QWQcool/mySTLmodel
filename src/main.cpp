#include<iostream>
#include"myString.h"
#include"Vector.h"
using namespace std;

int main()
{
	Vector<string> vt;
	vt.PushBack("cherno");
	vt.PushBack("C++");
	vt.PushBack("Vector");
	//myString类测试
	//cout << "/*--------------basic-------------------*/" << endl;
	//myString s1("-s1的构造-");
	//myString s2;
	//s2 = "-s2的构造-";
	//cout << "s2:" << s2 << endl;
	//cout <<"s2.size():" << s2.size() << endl;
	//cout << "s2.capacity(): " << s2.capacity() << endl;
	//myString s3 = s1; //走的深拷贝
	//s3[2] = '3';
	//cout <<"s3:" << s3 << endl;
	//cout << "/*--------------operator--------------*/" << endl;
	//if (s3 >= s2) {
	//	cout <<"if s3>=s2" << "yes" << endl;
	//}
	//myString s4 = s2 + s3;
	//cout <<"s4:" << s4 << endl;
	//myString s5 = s2 + s3;
	//s5 += s4;
	//cout <<"s5:" << s5 << endl;
	//cout << "/*---------------function------------*/" << endl;
	//s2.reserve(20);
	//cout << "s2.size():" << s2.size() << endl;
	//cout << "s2.capacity(): " << s2.capacity() << endl;
	//s3.append("s3的尾巴");
	//cout << "after append s3:" << s3 << endl;
	//s5.append(s3);
	//cout << "after append s5:" << s5 << endl;

	//s2.push_back('!');
	//cout << "after push_back s2:" << s2 << endl;  

	//myString s6 = "abcd";
	//s6.push_back('e');
	//cout <<"s6:" << s6 << endl;
	//int b=s6.find('b');
	//cout <<"b的位置:" << b << endl;
	//int cd = s6.find("cd");
	//cout << "cd的位置:" << cd << endl;
	//s6.insert('c', 2);
	//cout <<"after insert c pos 2:\n" << s6 << endl;
	//s6.insert('abc', 1);
	//cout <<"after insert abc pos 1:\n" << s6 << endl;
	return 0;
}
