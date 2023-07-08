#pragma once
#include <iostream>
using namespace std;
class points
{
	double x, y;
public:
	points() { x = y = 0; };
	~points() {};
	void put() { cin >> x; cin >> y; }
	void get() { cout << x << " " << y << endl; }
	double getx() { return x; }
	double gety() { return y; }
};
