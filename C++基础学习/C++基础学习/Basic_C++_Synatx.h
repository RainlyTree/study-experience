#pragma once
#include<iostream>
using namespace std;

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

	//���캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
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

private:
	int _year;
	int _month;
	int _day;
};