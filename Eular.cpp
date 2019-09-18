#define  _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
double cor[10000];
double f(double x, double y)//改写函数
{
	return x + y;
}
double correctf(double x)//精确解函数
{
	return -x - 1 + 2 * exp(x);
}
void Euler(double h, double l, double r, double *a, double *b, double tol)//欧拉法
{
	double sum = 0;
	for (int i = 1; i <= tol; i++)
	{
		b[i] = b[i - 1] + h*f(a[i - 1], b[i - 1]);
		sum += fabs(b[i] - cor[i]) / cor[i];
	}
	for (int i = 1; i <= tol; i++)
		printf("当x=%lf时，近似解为:%lf，准确解为:%lf\n", a[i], b[i], cor[i]);
	printf("精度为:%lf\n\n", sum / tol);
}
void improvedEuler(double h, double l, double r, double *a, double *b, double tol)//改进的欧拉法
{
	double b1, sum = 0;
	for (int i = 1; i <= tol; i++)
	{
		b1 = b[i - 1] + h*f(a[i - 1], b[i - 1]);
		b[i] = b[i - 1] + h / 2 * (f(a[i - 1], b[i - 1]) + f(a[i], b1));
	}
	for (int i = 1; i <= tol; i++)
		printf("当x=%lf时，近似解为:%lf，准确解为:%lf\n", a[i], b[i], cor[i]);
	printf("精度为:%lf\n\n", sum / tol);
}
void RungeKutta(double h, double l, double r, double *a, double *b, double tol)//四阶龙格库塔法
{
	double k1, k2, k3, k4, sum = 0;
	for (int i = 1; i <= tol; i++)
	{
		k1 = f(a[i - 1], b[i - 1]);
		k2 = f(a[i - 1] + h / 2, b[i - 1] + h / 2 * k1);
		k3 = f(a[i - 1] + h / 2, b[i - 1] + h / 2 * k2);
		k4 = f(a[i - 1] + h, b[i - 1] + h*k3);
		b[i] = b[i - 1] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	}
	for (int i = 1; i <= tol; i++)
		printf("当x=%lf时，近似解为:%lf，准确解为:%lf\n", a[i], b[i], cor[i]);
	printf("精度为:%lf\n\n", sum / tol);
}
int main_01()
{
	double h, a[10000], b[10000], l, r;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(cor, 0, sizeof(cor));
	printf("请输入步长:");
	scanf("%lf", &h);
	printf("请输入区间下限:");
	scanf("%lf", &l);
	printf("请输入区间上限:");
	scanf("%lf", &r);
	printf("请赋予初始值:");
	scanf("%lf", &b[0]);
	double tol = (r - l) / h;
	for (int i = 0; i <= tol; i++)
		a[i] = l + i*h;
	for (int i = 1; i <= tol; i++)
		cor[i] = correctf(a[i]);
	printf("以下为欧拉法求解结果:\n");
	Euler(h, l, r, a, b, tol);
	printf("以下为改进的欧拉法求解结果:\n");
	improvedEuler(h, l, r, a, b, tol);
	printf("以下为四阶龙格库塔法求解结果:\n");
	RungeKutta(h, l, r, a, b, tol);
	system("pause");
	return 0;
}