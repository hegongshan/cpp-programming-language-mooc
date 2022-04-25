#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
	private:
		int x, y;
		int **ptr;
	public:
		Array2() {
			ptr = nullptr;
		}
		Array2(int x, int y) :x(x), y(y) {
			this->ptr = new int*[x];
			for (int i = 0; i < x; i++) {
				this->ptr[i] = new int[y];
			}
		}
		~Array2() {
			for (int i = 0; i < x; i++) {
				delete [] ptr[i];
			}
                        delete [] ptr;	
		}
		int* operator[](int i) {
			return ptr[i];
		}
		int& operator()(int i, int j) {
			return ptr[i][j];
		}
		Array2& operator=(const Array2& a) {
			if (ptr) {
				delete [] ptr;
			}
			x = a.x;
			y = a.y;
			this->ptr = new int*[x];
                        for (int i = 0; i < x; i++) {
                               	this->ptr[i] = new int[y];
                        }		
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					this->ptr[i][j] = a.ptr[i][j];
				}
			}
			return *this;
		}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
