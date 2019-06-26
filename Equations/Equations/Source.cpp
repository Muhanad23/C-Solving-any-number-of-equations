#include<iostream>
#include"Matrix.h"
using namespace std;
int main()
{
	cout << "-----------------------------\n";
	cout << "//      instruction        //\n";
	cout << "-----------------------------\n\n";
	cout << "write every equation then press enter after every equation , and put spaces between every variable \n";
	cout << "Like this example: \n";
	cout << "2x+3y=5 ===============> 2 3 5\n";
	cout << "3x+8y=9 ===============> 3 8 9\n";
	l:cout << "______________________________________________________________________________________________________________________\n";
	cout << "Enter number of equations : ";
	int x;
	cin >> x;
	if (x < 1)
		cout << "are you stupid ?!!\n";
	char p;
	cout << "if you want to show steps (Gauss-Jordan method) press 1 else press any other integer :";
	cin >> p;
	int y = int(p);
	if (p == '1')
		y = 1;
	Matrix a(x);
	double *m = new double[x];
	cout << "Write the matrix (the equations as mentioned):\n";
	a.writeMatrix();
	if (y == 1)
	{
		cout << "the original matrix:\n";
		a.print();
	}
	cout << endl;
	bool test;
	m = a.solve(test,y);
	if (!test)
	{
		cout << "Can't solve these equations\n";
		goto l;
	}
	for (int i = 0; i < x; i++)
	{
		cout << "Variable #" << i + 1 << "  = ";
		cout << m[i] << endl;
	}
	goto l;
	return 0;
}