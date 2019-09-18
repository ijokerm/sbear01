#include<iostream>
#include<math.h>
using namespace std;

double *gauss_seidel(int n, double **a, double *b, double eps)
{
	int i, j;
	double p, t, s, q;
	double *x = new double[n];

	for (i = 0; i <= n - 1; i++)//这个大循环判断系数矩阵是否严格对角占优，是否适用高斯赛德尔迭代法
	{
		p = 0.0; x[i] = 0.0;
		for (j = 0; j <= n - 1; j++)
		if (i != j)   p = p + fabs(a[i][j]);
		if (p >= fabs(a[i][i]))
		{
			cout << "\n程序工作失败！" << endl;
			return NULL;
		}
	}
	//接下来就是正式的迭代计算
	p = eps + 1.0;
	while (p >= eps)//当精度还没达到的时候，继续迭代
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
	cout << "输入系数矩阵的阶数n:" << endl;
	cin >> n;
	cout << "依次输入系数矩阵的每一个元素A[i][j]:" << endl;
	A = new double *[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[n];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> A[i][j];
	b = new double[n];
	cout << "输入常数向量每一项b[i]:" << endl;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	double *x = new double[n];
	cout << "输入计算解的精度要求eps：" << endl;
	cin >> eps;
	x = gauss_seidel(n, A, b, eps);
	cout << "通过高斯—赛德尔迭代法计算得到的解：" << endl;
	for (int i = 0; i < n; i++)
		cout << "x" << i << "=" << x[i] << endl;
	system("pause");
	return 0;
}
