#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try {

	cout << "SizeOf:\n";
	cout << "char\t" << sizeof(char) << endl;
	cout << "short\t" << sizeof(short) << endl;
	cout << "int\t" << sizeof(int) << endl;
	cout << "long\t" << sizeof(long) << endl;
	cout << "float\t" << sizeof(float) << endl;
	cout << "double\t" << sizeof(double) << endl;
	cout << "int*\t" << sizeof(int*) << endl;
	cout << "double*\t" << sizeof(double*) << endl;
	
	cout << "\nMatrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);
	
	cout << "1D int, 10 elem\t\t" << sizeof(a) << endl;
	cout << "1D int, 100 elem\t\t" << sizeof(b) << endl;
	cout << "1D double, 10 elem\t\t" << sizeof(c) << endl;
	cout << "2D int, 10x10 elem\t\t" << sizeof(d) << endl;
	cout << "3D int, 10x10x10 elem\t\t" << sizeof(e) << endl;
	
	cout << "\nNumber of elements:\n";
	cout << "a:\t" << a.size() << endl;
	cout << "b:\t" << b.size() << endl;
	cout << "c:\t" << c.size() << endl;
	cout << "d:\t" << d.size() << endl;
	cout << "e:\t" << e.size() << endl;
	
	int i;
	cout << "Enter ints: ";
	while(cin >> i){
		errno = 0;
		double d = sqrt(i);
		if(errno == EDOM)
			cout << "no square root\n";
		else
			cout << "sqrt(" << i << ") = " << d << endl;
	}
	
	cin.clear();
	cin.ignore();
	
	cout << "Enter 10 floats: ";
	Matrix<double> m2(10);
	double d2;
	for(int i = 0; i < m2.size(); ++i){
		cin >> d2;
		if(!cin) throw runtime_error("Problem reading from cin!");
		m2[i] = d2;
	}
	cout << "Matrix:\n" << m2 << endl;
	
	cout << "Multiplication table:\n";
	double n, m3;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m3;
	Matrix<double, 2> mtable(n, m3);
	
	for(Index i = 0; i < mtable.dim1(); ++i){
		for(Index j = 0; j < mtable.dim2(); ++j){
			mtable(i, j) = (i+1)*(j+1);
			cout << setw(5) << mtable(i, j);
		}
		cout << endl;
	}
	
	Matrix<complex<double>> mcomp(10);
	cout << "\nEnter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for(int i = 0; i < 10; ++i){
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading from cin!");
		mcomp[i] = comp;
	}
	complex<double> sum;
	for(Index i = 0; i < mcomp.size(); ++i){
		sum += mcomp[i];
	}
	cout << "sum: " << sum << endl;
	
	Matrix<int, 2> m4(2, 3);
	cout << "Enter 6 ints: ";
	int num;
	for(int i = 0; i < m4.dim1(); ++i){
		for(int j = 0; j < m4.dim2(); ++j){
			cin >> num;
			m4(i, j) = num;
		}
		cout << endl;
	}
	cout << "Matrix:\n" << m4 << endl;
	
	
} catch(exception& e) {
	cout << "Exception: " << e.what() << endl;
} catch(...) {
	cout << "Unknown exception\n";
	return 2;
}
