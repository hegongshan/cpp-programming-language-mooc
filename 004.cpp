#include <iostream>
using namespace std;

int main()
{
	int * a[] = {
	// 在此处补充你的代码
		NULL,
		new int,
		new int,
		new int[6]
	};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}
