#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "classes.h"
#include "helpfunctions.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#define pi 3.14

using namespace std;

void treegraph()
{
	string out;
	out = "Длина забора равна ";
	int n, c = 0;
	double l = 0;
	double x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1, x4 = -1, y4 = -1, tx, ty, r, cw;
	double mw = 0;
	double minx = 0, maxx = 0, miny = 0, maxy = 0;
	double frp[3][2], fvp[4][2], sxp[5][2];
	int j = 0, z = 0;
	int ig4 = -1, ig51 = -1, ig52 = -1, ig61 = -1, ig62 = -1, ig63 = -1;
	points* crds;
	cout << "Введите кол-во сосен: ";
	while (1)
	{
		cin >> n;
		if (n >= 3) break;
	}
	crds = new points[n];
	for (int i = 0; i < n; i++) crds[i].put();
	//for (int i = 0; i < n; i++) crds[i].get();
	initwindow(1920, 1080);
	if (n == 3)
	{
		x1 = crds[0].getx(); y1 = crds[0].gety();
		x2 = crds[1].getx(); y2 = crds[1].gety();
		l += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		//line
		x1 = crds[0].getx(); y1 = crds[0].gety();
		x2 = crds[2].getx(); y2 = crds[2].gety();
		l += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		
		x1 = crds[1].getx(); y1 = crds[1].gety();
		x2 = crds[2].getx(); y2 = crds[2].gety();
		l += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		//Простой треугольник
		cout << l << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			treep(crds[i].getx(), crds[i].gety());
		}
		setcolor(RGB(255, 0, 255));
		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				line(crds[i].getx(), crds[i].gety(), crds[0].getx(), crds[0].gety());
			}
			else line(crds[i].getx(), crds[i].gety(), crds[i+1].getx(), crds[i+1].gety());
		}
	}
	else
	{
		if (n == 4)
		{
			minx = miny = 20000;
			maxx = maxy = -20000;
			for (int i = 0; i < n; i++)
			{
				tx = crds[i].getx();
				ty = crds[i].gety();
				if (tx < minx) minx = tx; if (tx > maxx) maxx = tx;
				if (ty < miny) miny = ty; if (ty > maxy) maxy = ty;
			}
			for (int i = 0; i < n; i++)
			{
				tx = crds[i].getx();
				ty = crds[i].gety();
				if (tx > minx)
				{
					if (tx < maxx)
					{
						if (ty > miny)
						{
							if (ty < maxy)
							{
								c++;
								ig4 = i;
							}
							else continue;
						}
						else continue;
					}
					else continue;
				}
				else continue;
			}
			if (c == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					if (i != ig4)
					{
						frp[j][0] = crds[i].getx();
						frp[j][1] = crds[i].gety();
						j++;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					treep(crds[i].getx(), crds[i].gety());
				}
				setcolor(RGB(255, 0, 255));
				//Как треугольник.
				for (int i = 0; i < 3; i++)
				{
					if (i == 2)
					{
						line(frp[i][0], frp[i][1], frp[0][0], frp[0][1]);
					}
					else line(frp[i][0], frp[i][1], frp[i + 1][0], frp[i + 1][1]);
				}
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					treep(crds[i].getx(), crds[i].gety());
				}
				setcolor(RGB(255, 0, 255));
				for (int i = 0; i < 4; i++)
				{
					if (i == 3)
					{
						x1 = crds[i].getx(); x2 = crds[0].getx();
						y1 = crds[i].gety(); y2 = crds[0].gety();
						l += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
						line(crds[i].getx(), crds[i].gety(), crds[0].getx(), crds[0].gety());
					}
					else
					{
						x1 = crds[i].getx(); x2 = crds[i + 1].getx();
						y1 = crds[i].gety(); y2 = crds[i + 1].gety();
						l += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
						line(crds[i].getx(), crds[i].gety(), crds[i + 1].getx(), crds[i + 1].gety());
					}
				}
			}
		}
		else
		{
			minx = miny = 20000;
			maxx = maxy = -20000;
			for (int i = 0; i < n; i++)
			{
				tx = crds[i].getx();
				ty = crds[i].gety();
				if (tx < minx) minx = tx; if (tx > maxx) maxx = tx;
				if (ty < miny) miny = ty; if (ty > maxy) maxy = ty;
			}
			centrum[0] = (minx + maxx) / 2;
			centrum[1] = (miny + maxy) / 2;
			for (int i = 0; i < n; i++)
			{
				tx = crds[i].getx();
				ty = crds[i].gety();
				cw = sqrt((tx - centrum[0]) * (tx - centrum[0]) + (ty - centrum[1]) * (tx - centrum[1]));
				if (cw > mw) mw = cw;
			}
			for (int i = 0; i < n; i++)
			{
				treep(crds[i].getx(), crds[i].gety());
			}
			r = mw;
			setcolor(RGB(255, 0, 255));
			circle(centrum[0], centrum[1], mw+1);
			l = 2 * pi * r;
			cout << l << endl;
		}
	}
	setcolor(RGB(255, 255, 0));
	out += to_string(l);
	char* outcc;
	const char* outc = out.c_str();
	outcc = (char*)outc;
	outtextxy(0, 0, outcc);
	_getch();
	closegraph();
}

void fractions()
{
	int X, Y, Z, F, G, H, A, B, C;
	int n;
	cout << "Введите целую часть первой дроби: "; X = input();
	cout << "Введите числитель первой дроби: "; Y = input();
	cout << "Введите знаменатель первой дроби: "; Z = input();
	cout << "Введите целую часть второй дроби: "; F = input();
	cout << "Введите числитель второй дроби: "; G = input();
	cout << "Введите знаменатель второй дроби: "; H = input();;

	if ((Y >= Z) && (Z != 0)) { X = X + Y / Z; while (Y >= Z) Y = Y - Z; }
	if ((G >= H) && (H != 0)) { F = F + G / H; while (G >= H) G = G - H; }

	cout << "Нажми + для сложения, - для вычитания" << endl;
	switch (_getch())
	{
	case '+':
		if (Z != H)
		{
			Y = Y * (NOK(Z, H) / Z);
			G = G * (NOK(Z, H) / H);
			Z = H = NOK(Z, H);
		}
		A = X + F; B = Y + G; C = NOK(Z, H);
		A = A + B / C; while (B >= Z) B = B - C;
		n = NOD(B, C); B = B / n; C = C / n;
		output(A, B, C);
		break;
	case '-': 
		if (X >= F)
		{
			if (Z != H)
			{
				Y = Y * (NOK(Z, H) / Z);
				G = G * (NOK(Z, H) / H);
				Z = H = NOK(Z, H);
			}

			if (Y < G) { X -= 1; Y += Z; }

			A = X - F; B = Y - G; C = NOK(Z, H);
			A = A + B / C;
			while (B >= Z) B = B - C;
		}
		else
		{
			if (Z != H)
			{
				Y = Y * (NOK(Z, H) / Z);
				G = G * (NOK(Z, H) / H);
				Z = H = NOK(Z, H);
			}

			if (G < Y) { F -= 1; G += H; }

			A = (F - X) * -1; B = G - Y;
			C = NOK(Z, H); A = A - B / C;
			while (B >= Z) B = B - C;
		}
		output(A, B, C);
		break;
	}
	_getch();
}
void newtonmethod(double x0)
{
	double x = x0;
	int i = 0;
	while (abs(f(x)) > 1e-10 && i < 100)
	{
		x = x - f(x) / df(x);
		i++;
	}
	cout << fixed << setprecision(3);
	cout << "x1 = +" << x << endl;
	x *= -1;
	cout << "x2 = " << x << endl;
	_getch();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int l = 1;

	while (l == 1)
	{
		cout << endl << "Нажмите 1 для выполнения задачи 42." << endl;
		cout << "Нажмите 2 для выполнения задачи 48" << endl;
		cout << "Нажмите 3 для выполнения задачи 37" << endl;
		cout << "Нажмите 0 для выхода." << endl << endl;
		switch (_getch())
		{
		case '1': treegraph(); break;
		case '2': fractions(); break;
		case '3': newtonmethod(2); break;
		case '0': l = 0; break;
		}
		system("cls");
	}
	return 0;
}
