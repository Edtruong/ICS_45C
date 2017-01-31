#include "Matrix.h"
#include "Array.h"
using namespace std;

template
	<typename T>
void fillMatrix(Matrix<T> & m)
{
	int i, j;
	for(i = 0; i < m.numRows(); i++)
		m[i][0] = T();
	for(j = 0; j < m.numCols(); j++)
		m[0][j] = T();
	for(i = 1; i < m.numRows(); i++)
		for(j = 1; j < m.numCols(); j++)
		{
			m[i][j] = T(i * j);
		}
}
void test_int_matrix()
{
	Matrix <int> m(10,5);
	fillMatrix(m);
	cout << m << endl;
	cout << "Testing illegal index -1" << endl;
	try
	{
		m[-1] = Array<int> (5); //Should raise exception
	}
	catch(IndexOutOfBounds & e)
	{
		cout << "Error: Index is out of bounds" << endl;
	}
}
void test_double_matrix()
{
	Matrix <double> M(8,10);
	fillMatrix(M);
	cout << M << endl;
	cout << "Testing illegal index 100" << endl;
	try
	{
		M[100] = Array<double> (5); // Should raise exception
	}
	catch(IndexOutOfBounds & e)
	{
		cout << "Error: Index is out of bounds" << endl;
	}
}

int main()
{
	cout << "Testing 1" << endl;
	test_int_matrix();
	cout << "Testing 2" << endl;
	test_double_matrix();
	return 0;
}

