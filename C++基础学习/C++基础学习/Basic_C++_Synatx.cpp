#include "Basic_C++_Synatx.h"

void textDate()
{

	Date d;
	d.SetDate(2019, 10, 22);
	d.Display();

	//�޲ι��첻��Ҫ��()
	// ����֮����Ǻ�������
	//Date d3();

	Date d2(2019, 10, 23);
	//d2.SetDate(2019, 10, 23);
	d2.Display();

	//��������
	Date d3(d2);
	Date d4 = d3;
	Date d5(Date(2019, 10, 23));
}

int main()
{
	textDate();
	//system("pause");
	return 0;
}

