#include <iostream>
#include <vector>
using namespace std;

void mySort(vector<int>& v, int begin, int end) {
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
void Output(vector<int> v) {
	for (int ele : v) {
		cout << ele << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> myv = { 4,2,5,1,3,8,6,7 };
	Output(myv);
	mySort(myv, 0, 7);
	Output(myv);
	return 0;
}