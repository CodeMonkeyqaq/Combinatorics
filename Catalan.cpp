#include <iostream>
#include <time.h>
using namespace std;

double digui(int x);     //�ݹ鷽ʽ
double tongxiang(int x);    //ͨ�ʽ

int main() 
{
	int x = 0;    //�û�����
	double time[31];   //ʱ������
	int startTime, endTime;    //��ֹʱ��
	cout << "������һ��1~30֮�������" << endl;
	while (1)
	{
		if (!(cin >> x)) //����ʧ��
		{
			cout << "����Ƿ������������롣" << endl;
			cin.clear();    //�������
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		else
		{
			if (x > 30)    //����Խ��
			{
				cout << "������30���µ�������" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
			}
			else if (x <= 1)    //���ն��壬1�����޿�������
			{
				cout << "������1���ϵ�������������1��" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
			}
			else
			{
				break;
			}
		}
	}
	//��Catalan��
	cout << "�ݹ鷽�������" << endl;
	for (int i = 2; i <= x; i++)
	{
		cout << digui(i) << " ";
	}
	cout << endl;
	cout << "ͨ�ʽ���������" << endl;
	for (int i = 2; i <= x; i++)
	{
		cout << tongxiang(i) << " ";
	}
	cout << endl;
	cout << "�ݹ鷽��ʱ�䣺���Եȣ�" << endl;
	for (int j = 2; j <= 30; j++)
	{
		startTime = clock();    //��ʱ��ʼ
		for (int i = 0; i < 1000000; i++)    //����һ�����
		{
			digui(j);
		}
		endTime = clock();   //��ʱ����
		time[j] = (double)(endTime - startTime) / CLOCKS_PER_SEC;   //��������time����λ��
	}
	for (int i = 2; i <= 30; i++)
	{
		cout << time[i] << " ";
	}
	cout << endl;
	cout << "ͨ�ʽ����ʱ�䣺���Եȣ�" << endl;
	for (int j = 2; j <= 30; j++)
	{
		startTime = clock();
		for (int i = 0; i < 1000000; i++)
		{
			tongxiang(j);
		}
		endTime = clock();
		time[j] = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	}
	for (int i = 2; i <= 30; i++)
	{
		cout << time[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

//���ƹ�ϵ�㷨
double digui(int x)
{
	if (x == 2)
	{
		return 1;
	}
	else
	{
		return double(4 * x - 10) / (x - 1)*digui(x - 1);
	}
}

//ͨ�ʽ�㷨
double tongxiang(int x)
{
	double result = 1;   //���
	if (x == 2)
	{
		return result;
	}
	else
	{
		double t = x - 1;    //���ȼ�¼������x�ı���޷�����
		while (x > 2)
		{
			result = result * (2 * x - 4)* (2 * x - 5) / (x - 2) / (x - 2);
			x--;
		}
		result = result / t;
		return result;
	}
}
