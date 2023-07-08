#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

using namespace std;
double centrum[2];

int NOD(int n1, int n2)
{
	int div;
	if (n1 == n2)  return n1;
	int d = n1 - n2;
	if (d < 0) { d = -d;  div = NOD(n1, d); }
	else div = NOD(n2, d);
	return div;
}

int NOK(int n1, int n2) { return n1 * n2 / NOD(n1, n2); }

int input()
{
	int n;
	while (1) { cin >> n; if (n <= 1000) break; }
	return n;
}

void output(int A, int B, int C)
{
	if (A != 0)
	{
		if (B != 0) cout << A << " " << B << "/" << C << endl;
		else cout << A << endl;
	}
	else
	{
		if (B != 0) cout << B << "/" << C << endl;
		else cout << "0" << endl;
	}
}

double f(double x)
{
	return x * x - 7.0;
}

double df(double x)
{
	return 2 * x;
}

void treep(double x, double y)
{
	setcolor(RGB(0,255,0));
	line(x - 10, y, x + 10, y);
	line(x, y - 10, x, y + 10);
}
