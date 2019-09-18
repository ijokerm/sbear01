#include<iostream>
#include<math.h>
using namespace std;

double *gauss_seidel(int n, double **a, double *b, double eps)
{
	int i, j;
	double p, t, s, q;
	double *x = new double[n];

	for (i = 0; i <= n - 1; i++)//�����ѭ���ж�ϵ�������Ƿ��ϸ�Խ�ռ�ţ��Ƿ����ø�˹���¶�������
	{
		p = 0.0; x[i] = 0.0;
		for (j = 0; j <= n - 1; j++)
		if (i != j)   p = p + fabs(a[i][j]);
		if (p >= fabs(a[i][i]))
		{
			cout << "\n������ʧ�ܣ�" << endl;
			return NULL;
		}
	}
	//������������ʽ�ĵ�������
	p = eps + 1.0;
	while (p >= eps)//�����Ȼ�û�ﵽ��ʱ�򣬼�������
	{
		p = 0.0;
		for (i = 0; i <= n - 1; i++)
		{
			t = x[i]; s = 0.0;
			for (j = 0; j <= n - 1; j++)
			if (j != i) s = s + a[i][j] * x[j];
			x[i] = (b[i] - s) / a[i][i];
			q = fabs(x[i] - t) / (1.0 + fabs(x[i]));
			if (q>p) p = q;
		}
	}
	return x;
}
int main_a()
{
	double **A, *b, eps;
	int n;
	cout << "����ϵ������Ľ���n:" << endl;
	cin >> n;
	cout << "��������ϵ�������ÿһ��Ԫ��A[i][j]:" << endl;
	A = new double *[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[n];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> A[i][j];
	b = new double[n];
	cout << "���볣������ÿһ��b[i]:" << endl;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	double *x = new double[n];
	cout << "��������ľ���Ҫ��eps��" << endl;
	cin >> eps;
	x = gauss_seidel(n, A, b, eps);
	cout << "ͨ����˹�����¶�����������õ��Ľ⣺" << endl;
	for (int i = 0; i < n; i++)
		cout << "x" << i << "=" << x[i] << endl;
	system("pause");
	return 0;
}
