#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {

	private:
		string name;
		int age;
		int no;
		int grade[4];
		double average;
	public:
		void input() {
			string x;
			getline(cin, name, ',');
			getline(cin, x, ',');
			age = atoi(x.c_str());

			getline(cin, x, ',');
			no = atoi(x.c_str());
			for (int i = 0; i < 4; i++) {
				if (i == 3) {
					cin >> grade[i];
				} else {
					getline(cin, x, ',');
					grade[i] = atoi(x.c_str());
				}
			}
		}
		void calculate() {
			average = 0;
			for (int i = 0; i < 4; i++) {
				average += grade[i];
			}
			average /= 4.0;
		}
		void output() {
			cout << name << ',' << age << ',' << no << ',' << average << endl;
		}
};
/*class Student {
// 在此处补充你的代码
	private:
		string name;
		int age;
		int no;
		int grade[4];
		double average;	
	public:
		void input();
		void calculate();
		void output();
};	

void Student::input() {
	string x;
	getline(cin, name, ',');
	getline(cin, x, ',');
	age = stoi(x);
	getline(cin, x, ',');
	no = stoi(x);
	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			cin >> grade[i];
		} else {
			getline(cin, x, ',');
			grade[i] = stoi(x);
		}
	}
}

void Student::calculate() {
	average = 0;
	for (int i = 0; i < 4; i++) {
		average += grade[i];
	}
	average /= 4.0;
}

void Student::output() {
	cout << name << ',' << age << ',' << no << ',' << average << endl;
}*/

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
