#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal" << endl;
	}
	virtual void speak() = 0;
};

class Cat : public Animal{
public:
	Cat() {
		cout << "Cat" << endl;
	}
	void speak() {
		cout << "miao" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog" << endl;
	}
	void speak() {
		cout << "wang" << endl;
	}
};

int main() {
	int n;
	cin >> n;
	vector<Animal*> v(2 * n);
	for (int i = 0; i < n; ++i) {
		Dog dog;
		Cat cat;
		Animal* pd = &dog;
		Animal* pc = &cat;
		v.push_back(pd);
		v.push_back(pc);
	}
	return 0;
}