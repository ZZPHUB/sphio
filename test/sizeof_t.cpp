#include <iostream>
using namespace std;
int main(void)
{
	int a[100] = {0};
	double *b = new double[99999];
	cout << sizeof(a) << " " << sizeof(&b) << endl;
	//int *p = ((int *)b-4);
	//cout << *p << endl;
	cout << b.size() << endl;
	return 0;
}
