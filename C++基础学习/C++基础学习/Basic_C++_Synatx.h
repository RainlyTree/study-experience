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
		this ָ��:������ * const
				ָ��ǰ�����ָ��
				������Ա�����ĵ�һ������
				ֻ���ڳ�Ա������
	*/
	
	//�ײ� ��void SetDate(Date* const this ,int year, int month, int day)

	//���캯�� ������������ֻ����һ��
	//���Լ������ �����������ڹ���
	//Ĭ�Ϲ��� ��
	//			1.�޲ι���
	//			2.������Ĭ������
	//			3.ȫȱʡ�Ĺ��캯��
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

	//�������죺�ǹ��캯����һ������
	//const �Ǳ�֤��ʱ����
	//������Ĭ�����ɵĿ�������:�ֽڿ�����Ҳ��Ϊǳ����
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


	//��������   ��֧������   �������ٶ���  ֻ����������
	//���ٶ����ڱ�����
	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	//������Ĭ�����ɵĹ��캯����
	//	�������ͣ��޲���
	//	�Զ������ͣ�������Զ������͵�Ĭ�Ϲ��캯��������Զ���ĳ�Ա����
	//	�Զ������ͣ������������������������
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
