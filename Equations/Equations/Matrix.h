#pragma once
class Matrix
{
	int size;
	double **a;
	double *result;
public:
	Matrix(int);
	void writeMatrix();
	double* solve(bool&,int);
	void print()const;
	~Matrix();
};

