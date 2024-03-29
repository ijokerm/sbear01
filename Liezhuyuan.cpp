#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int m, n, i, j, k;
float a[15][15], temp[15], d;
void main_1()
{
	cout << "请问所输入的系数矩阵行数为：";
	cin >> m;
	cout << "请问所输入的系数矩阵列数为：";
	cin >> n;
	if (m <= 0 || n <= 0)
	{
		cout << "输入的格式有误！\n";
	}

	for (i = 0; i < m; i++)
	{
		cout << "请输入第" << i + 1 << "行的系数：";
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "请输入未知向量的值：";
	for (i = 0; i < m; i++)
	{
		cin >> a[i][n];
	}

	cout << "该方程组的增广矩阵为:\n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	for (k = 0; k < n - 1; k++) //找列主元最大值
	{
		double max = 0;
		int hang = 0, num = 0;
		for (i = k; i < n; i++)
		{
			if (fabs(a[i][k]) > max)//fabs 求整数的绝对值
			{
				max = fabs(a[i][k]);
				hang = i;
			}
		}
		if (a[hang][k] == 0)
		{
			cout << "无法计算" << endl;
			return;
		}
		if (k != hang) //换行
		{
			for (i = 0; i < m + 1; i++)
			{
				temp[i] = a[k][i];
				a[k][i] = a[hang][i];
				a[hang][i] = temp[i];
			}
		}
		cout << "选列主元:\n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		for (i = k + 1; i < m; i++) //消元
		{
			d = a[i][k] / a[k][k];
			for (j = 0; j < n + 1; j++)
			{
				a[i][j] = a[i][j] - d * a[k][j];
			}
		}
		cout << "消元:\n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
	memset(temp, 0, 15 * sizeof(float)); //将temp清0，准备存放解向量
	for (i = m - 1; i >= 0; i--) //求解向量
	{
		d = 0;
		for (k = 0; k < n; k++)
		{
			d = d + temp[k] * a[i][k];
		}
		temp[i] = (a[i][n] - d) / a[i][i];
	}
	cout << "此方程组的解向量转置为：("; //输出解向量
	for (i = 0; i < m; i++)
	{
		cout << " " << fixed << setprecision(5) << temp[i];//5位小数
	}
	cout << " )" << endl;
	system("pause");
}