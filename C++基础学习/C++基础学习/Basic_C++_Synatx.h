#pragma once
#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
};


class Date
{
public:
	/*
		this 指针:类类型 * const
				指向当前对象的指针
				做诶成员函数的第一个参数
				只存在成员函数中
	*/
	
	//底层 ：void SetDate(Date* const this ,int year, int month, int day)

	//构造函数 整个生命周期只调用一次
	//若自己构造后 编译器不会在构造
	//默认构造 ：
	//			1.无参构造
	//			2.编译期默认生成
	//			3.全缺省的构造函数
	Date()
	{
		cout << "Date()" << endl;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造：是构造函数的一种重载
	//const 是保证临时变量
	//编译器默认生成的拷贝构造:字节拷贝，也称为浅拷贝
	Date(const Date& date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}


	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << " " << _month  << " " << _day << endl;
	}


	//析构函数   不支持重载   不是销毁对象  只是用于清理
	//销毁对象在编译器
	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	//编译器默认生成的构造函数：
	//	内置类型：无操作
	//	自定义类型：会调用自定义类型的默认构造函数，完成自定义的成员定义
	//	自定义类型：除了内置类型外的所有类型
	int _year;
	int _month;
	int _day;
	A _a;
};


class String
{
public:
	String(char* str)
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}

private:
	char* _str;
};
