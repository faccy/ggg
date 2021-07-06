#include <iostream>
#include <vector>
using namespace std;
template<class T>
void mySort(vector<T>& v, int begin, int end) {
	if (begin < end) {
		int key = v[begin];
		int i = begin, j = end;
		while (i < j) {
			while (i < j && v[j] > key) {
				j--;
			}
			if (i < j) {
				v[i] = v[j];
				i++;
			}
			while (i < j && v[i] < key) {
				i++;
			}
			if (i < j) {
				v[j] = v[i];
				j--;
			}
			v[i] = key;
			mySort(v, begin, i - 1);
			mySort(v, i + 1, end);
		}
	}
}
template<class T>
void Output(vector<T> v) {
	for (auto ele : v) {
		cout << ele << " ";
	}
	cout << endl;
}

int main()
{
	vector<char> myv = { 'h','i','a','c','e','d','b','g','f' };
	Output(myv);
	mySort(myv, 0, 7);
	Output(myv);
	return 0;
}