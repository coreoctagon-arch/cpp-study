#include<bits/stdc++.h>
using namespace std;

class Shape{
private:
	char* name;
	static int count;
public:
	Shape(const char* n)
	{
		name=new char[strlen(n)+1];
		strcpy(name,n);
		count++;
	}
	Shape(const Shape& other)
	{
		name=new char[strlen(other.name)+1];
		strcpy(name,other.name);
		count++;
	}
	Shape& operator=(const Shape& other)
	{
		if(this==&other) return *this;
		delete[] name;
		name=new char[strlen(other.name)+1];
		strcpy(name,other.name);
		return *this;
	}
	virtual ~Shape()
	{
		delete[] name;
		count--;
	}
	virtual double area() const=0;
	virtual double perimeter() const=0;
	
	static int getCount()
	{
		return count;
	}
	friend ostream& operator<<(ostream& out,const Shape& other);
	
	bool operator<(const Shape& other) const
	{
		return area()<other.area();
	}
};

ostream& operator<<(ostream& out,const Shape& other)
{
	out<<other.name<<" area="<<other.area()<<" perimeter="<<other.perimeter();
	return out;
}

class Circle:public Shape{
private:
	double radius;
public:
	Circle(const char* n,double r):Shape(n),radius(r){}
	double area() const override
	{
		return 3.14 * radius * radius;
	}
	double perimeter() const override
	{
		return 2 * 3.14 * radius;
	}
};

class Rectangle:public Shape{
private:
	double width;
	double height;
public:
	Rectangle(const char* n,double w,double h):Shape(n),width(w),height(h){}
	double area() const override
	{
		return width * height;
	}
	double perimeter() const override
	{
		return 2 * (width + height);
	}
	
};

int Shape::count=0;
int main() {
    Circle c1("circleA", 2);
    Circle c2 = c1;

    Rectangle r1("rectA", 3, 4);

    Shape* p1 = new Circle("circleB", 1);
    Shape* p2 = new Rectangle("rectB", 5, 6);

    cout << c1 << endl;
    cout << c2 << endl;
    cout << r1 << endl;

    cout << p1->area() << endl;
    cout << p2->area() << endl;

    cout << (c1 < r1) << endl;

    delete p1;
    delete p2;

    cout << Shape::getCount() << endl;

    return 0;
}