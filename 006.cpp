#include <iostream>
using namespace std;
class Sample {
public:
	int v;
	// 在此处补充你的代码
	Sample() {}
	Sample(int value) : v(value) {}
	Sample(const Sample & a) {
		this->v = a.v + 2;
	}
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}
