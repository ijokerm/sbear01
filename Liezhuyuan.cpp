#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int m, n, i, j, k;
float a[15][15], temp[15], d;
void main_1()
{
	cout << "�����������ϵ����������Ϊ��";
	cin >> m;
	cout << "�����������ϵ����������Ϊ��";
	cin >> n;
	if (m <= 0 || n <= 0)
	{
		cout << "����ĸ�ʽ����\n";
	}

	for (i = 0; i < m; i++)
	{
		cout << "�������" << i + 1 << "�е�ϵ����";
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "������δ֪������ֵ��";
	for (i = 0; i < m; i++)
	{
		cin >> a[i][n];
	}

	cout << "�÷�������������Ϊ:\n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	for (k = 0; k < n - 1; k++) //������Ԫ���ֵ
	{
		double max = 0;
		int hang = 0, num = 0;
		for (i = k; i < n; i++)
		{
			if (fabs(a[i][k]) > max)//fabs �������ľ���ֵ
			{
				max = fabs(a[i][k]);
				hang = i;
			}
		}
		if (a[hang][k] == 0)
		{
			cout << "�޷�����" << endl;
			return;
		}
		if (k != hang) //����
		{
			for (i = 0; i < m + 1; i++)
			{
				temp[i] = a[k][i];
				a[k][i] = a[hang][i];
				a[hang][i] = temp[i];
			}
		}
		cout << "ѡ����Ԫ:\n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		for (i = k + 1; i < m; i++) //��Ԫ
		{
			d = a[i][k] / a[k][k];
			for (j = 0; j < n + 1; j++)
			{
				a[i][j] = a[i][j] - d * a[k][j];
			}
		}
		cout << "��Ԫ:\n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
	memset(temp, 0, 15 * sizeof(float)); //��temp��0��׼����Ž�����
	for (i = m - 1; i >= 0; i--) //�������
	{
		d = 0;
		for (k = 0; k < n; k++)
		{
			d = d + temp[k] * a[i][k];
		}
		temp[i] = (a[i][n] - d) / a[i][i];
	}
	cout << "�˷�����Ľ�����ת��Ϊ��("; //���������
	for (i = 0; i < m; i++)
	{
		cout << " " << fixed << setprecision(5) << temp[i];//5λС��
	}
	cout << " )" << endl;
	system("pause");
}