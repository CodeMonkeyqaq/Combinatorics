#include <iostream>
#include <time.h>
using namespace std;

double digui(int x);     //递归方式
double tongxiang(int x);    //通项公式

int main() 
{
	int x = 0;    //用户输入
	double time[31];   //时间数组
	int startTime, endTime;    //起止时间
	cout << "请输入一个1~30之间的整数" << endl;
	while (1)
	{
		if (!(cin >> x)) //输入失败
		{
			cout << "输入非法，请重新输入。" << endl;
			cin.clear();    //清空输入
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		else
		{
			if (x > 30)    //输入越界
			{
				cout << "请输入30以下的整数。" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
			}
			else if (x <= 1)    //按照定义，1以下无卡塔兰数
			{
				cout << "请输入1以上的整数，不包括1。" << endl;
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
	//求Catalan数
	cout << "递归方法结果：" << endl;
	for (int i = 2; i <= x; i++)
	{
		cout << digui(i) << " ";
	}
	cout << endl;
	cout << "通项公式方法结果：" << endl;
	for (int i = 2; i <= x; i++)
	{
		cout << tongxiang(i) << " ";
	}
	cout << endl;
	cout << "递归方法时间：（稍等）" << endl;
	for (int j = 2; j <= 30; j++)
	{
		startTime = clock();    //计时开始
		for (int i = 0; i < 1000000; i++)    //运行一百万次
		{
			digui(j);
		}
		endTime = clock();   //计时结束
		time[j] = (double)(endTime - startTime) / CLOCKS_PER_SEC;   //存入数组time，单位秒
	}
	for (int i = 2; i <= 30; i++)
	{
		cout << time[i] << " ";
	}
	cout << endl;
	cout << "通项公式方法时间：（稍等）" << endl;
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

//递推关系算法
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

//通项公式算法
double tongxiang(int x)
{
	double result = 1;   //结果
	if (x == 2)
	{
		return result;
	}
	else
	{
		double t = x - 1;    //事先记录，以免x改变后无法计算
		while (x > 2)
		{
			result = result * (2 * x - 4)* (2 * x - 5) / (x - 2) / (x - 2);
			x--;
		}
		result = result / t;
		return result;
	}
}
