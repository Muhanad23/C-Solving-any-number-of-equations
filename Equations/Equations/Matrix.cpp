#include "Matrix.h"
#include<iostream>
using namespace std;


Matrix::Matrix(int x)
{
	size = x;
	a = new double*[x];
	for (int i = 0; i < x; i++)
		a[i] = new double[x+1];
	result = new double[x];
}

void Matrix::writeMatrix()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
			cin >> a[i][j];
	}
}

double* Matrix::solve(bool & test,int y)
{
	test = true;
	double x;
	for (int i = 0; i < size; i++)
	{
		if (a[i][i] == 0)
		{
			for (int l = i+1; l < size; l++)
			{
				if (a[l][i] != 0)
				{
					test = true;
					cout << "R" << i+1  << " <-> " << "R" << l + 1 << endl;
					double *aa = a[i];
					a[i] = a[l];
					a[l] = aa;
					print();
					cout << endl;
					break;
				}
				else
					test = false;
			}
		}
		if (!test)
			return result;
		if (a[i][i] != 1 && a[i][i]!=0)
		{
			x = a[i][i];
			for (int n = 0; n < size + 1; n++)
			{
				a[i][n] /= x;
				if (a[i][n] == -0)
					a[i][n] = 0;
			}
			if (y == 1)
			{
				cout << "R" << i + 1 << " /" << x << " ->R" << i + 1 <<" :"<< endl;
				print();
				cout << endl;
			}
		}
		for (int j = 0; j < size; j++)
		{
			x = a[j][i];
			if (i != j)
			{
				for (int n = 0; n < size + 1; n++)
					a[j][n] -= x*a[i][n];
				if (y == 1)
				{
					cout <<"-("<< x << "*R" << i + 1 << ")+R" << j + 1 << " -> R" << j + 1 << " :" << endl;
					print();
					cout << endl;
				}
			}
		}
		
	}
	for (int i = 0; i < size; i++)
		result[i] = a[i][size];
	return result;
}

void Matrix::print()const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
		delete[]a[i];
	delete []a;
	delete result;
}
