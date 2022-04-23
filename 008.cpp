#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    // 在此处补充你的代码
    Complex() {}
    Complex(const char *str) {
    	const char *pos_plus = strchr(str, '+');
	const char *pos_i = strchr(str, 'i');
	
	char pr[pos_plus - str];
        char pi[pos_i - pos_plus];
	
	strncpy(pr, str, sizeof(pr));
	strncpy(pi, pos_plus + 1, sizeof(pi));
	
	r = atof(pr);
	i = atof(pi);
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
