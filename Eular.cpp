#define  _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
double cor[10000];
double f(double x, double y)//��д����
{
	return x + y;
}
double correctf(double x)//��ȷ�⺯��
{
	return -x - 1 + 2 * exp(x);
}
void Euler(double h, double l, double r, double *a, double *b, double tol)//ŷ����
{
	double sum = 0;
	for (int i = 1; i <= tol; i++)
	{
		b[i] = b[i - 1] + h*f(a[i - 1], b[i - 1]);
		sum += fabs(b[i] - cor[i]) / cor[i];
	}
	for (int i = 1; i <= tol; i++)
		printf("��x=%lfʱ�����ƽ�Ϊ:%lf��׼ȷ��Ϊ:%lf\n", a[i], b[i], cor[i]);
	printf("����Ϊ:%lf\n\n", sum / tol);
}
void improvedEuler(double h, double l, double r, double *a, double *b, double tol)//�Ľ���ŷ����
{
	double b1, sum = 0;
	for (int i = 1; i <= tol; i++)
	{
		b1 = b[i - 1] + h*f(a[i - 1], b[i - 1]);
		b[i] = b[i - 1] + h / 2 * (f(a[i - 1], b[i - 1]) + f(a[i], b1));
	}
	for (int i = 1; i <= tol; i++)
		printf("��x=%lfʱ�����ƽ�Ϊ:%lf��׼ȷ��Ϊ:%lf\n", a[i], b[i], cor[i]);
	printf("����Ϊ:%lf\n\n", sum / tol);
}
void RungeKutta(double h, double l, double r, double *a, double *b, double tol)//�Ľ����������
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
		printf("��x=%lfʱ�����ƽ�Ϊ:%lf��׼ȷ��Ϊ:%lf\n", a[i], b[i], cor[i]);
	printf("����Ϊ:%lf\n\n", sum / tol);
}
int main_01()
{
	double h, a[10000], b[10000], l, r;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(cor, 0, sizeof(cor));
	printf("�����벽��:");
	scanf("%lf", &h);
	printf("��������������:");
	scanf("%lf", &l);
	printf("��������������:");
	scanf("%lf", &r);
	printf("�븳���ʼֵ:");
	scanf("%lf", &b[0]);
	double tol = (r - l) / h;
	for (int i = 0; i <= tol; i++)
		a[i] = l + i*h;
	for (int i = 1; i <= tol; i++)
		cor[i] = correctf(a[i]);
	printf("����Ϊŷ���������:\n");
	Euler(h, l, r, a, b, tol);
	printf("����Ϊ�Ľ���ŷ���������:\n");
	improvedEuler(h, l, r, a, b, tol);
	printf("����Ϊ�Ľ���������������:\n");
	RungeKutta(h, l, r, a, b, tol);
	system("pause");
	return 0;
}