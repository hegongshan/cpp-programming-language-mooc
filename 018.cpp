#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
private:
	char s[210];

public:
	CHugeInt(char s[]) {
		memset(this->s, '\0', sizeof(this->s));
		strcpy(this->s, s);
	}

	CHugeInt(int n) {
		memset(this->s, '\0', sizeof(this->s));
		sprintf(s, "%d", n);
	}
	
	CHugeInt operator+(const CHugeInt& b) {
		CHugeInt a(0);
		int carry = 0;
		int la = strlen(this->s);
		int lb = strlen(b.s);
		int len = la > lb ? la : lb;

		int i = la - 1;
		int j = lb - 1;
		int k = len - 1;
		while (i >= 0 || j >= 0) {
			int da = i >= 0 ? s[i] - '0' : 0;
			int db = j >= 0 ? b.s[j] - '0' : 0;
                        int d = da + db + carry;
                        
			a.s[k--] = d % 10 + '0';
			carry = d / 10;

                        i --;
			j --;
                }
		if (carry > 0) {
			for (int x = len - 1; x >= 0; x--) {
				a.s[x + 1] = a.s[x];
			}
			a.s[0] = carry + '0';
		}
                return a;
	}

	CHugeInt operator+(int n) {
		return *this + CHugeInt(n);
	}

	friend CHugeInt operator+(int n, CHugeInt& a) {
		return a + n;
	}

	CHugeInt& operator+=(int n) {
		*this = *this + n;
		return *this;
	}

	CHugeInt& operator++() {	
		*this = *this + 1;
		return *this;
	}

	CHugeInt operator++(int n) {
		CHugeInt tmp(this->s);
		*this = *this + 1;
		return tmp;
	}

	friend ostream& operator<<(ostream& os, const CHugeInt& a) {
		int len = strlen(a.s);
		for (int i = 0; i < len; i++) {
			os << a.s[i];
		}
		return os;
	}
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
