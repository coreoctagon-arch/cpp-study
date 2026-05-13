#include<bits/stdc++.h>
using namespace std;

class MyString{
private:
	char* str;
public:
	MyString(const char* s="")
	{
		str=new char[strlen(s)+1];
		strcpy(str,s);
	}
	MyString(const MyString& other)
	{
		str=new char[strlen(other.str)+1];
		strcpy(str,other.str);
	}
	MyString& operator=(const MyString& other)
	{
		if(this==&other) return *this;
		delete[] str;
		
		str=new char[strlen(other.str)+1];
		strcpy(str,other.str);
		return *this;
	}
	MyString operator+(const MyString& other)
	{
		char* tmp=new char[strlen(str)+strlen(other.str)+1];
		strcpy(tmp,str);
		strcat(tmp,other.str);
		
		MyString ret(tmp);
		delete[] tmp;
		return ret;
	}
	friend ostream& operator<<(ostream& out,const MyString& s);
	
	~MyString()
	{
		delete[] str;
	}
};

ostream& operator<<(ostream& out,const MyString& s)
{
	out<<s.str;
	return out;
}

int main()
{
	MyString a("Hello");
MyString b("World");
MyString c = a + b;
cout << c;
	return 0;
}