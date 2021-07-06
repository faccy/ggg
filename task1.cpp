<<<<<<< HEAD
#include <iostream>
using namespace std;

//lesson 1 task
int main()
{
	int m, n;
	cin >> m >> n;
	int sum = 1;
	int dmin = min(m, n);
	int dmax = max(m, n);
	for (int i = 1; i < dmin; ++i) {
		sum *= pow(2, 2 * i);
	}
	int temp = dmax - dmin;
	for (int i = 0; i <= temp; ++i) {
		sum *= pow(2, dmin);
	}
	cout << "共有" << sum << "种路径。" << endl;
	return 0;
=======
#include <iostream>
using namespace std;

//lesson 1 task
int main()
{
	int m, n;
	cin >> m >> n;
	int sum = 1;
	int dmin = min(m, n);
	int dmax = max(m, n);
	for (int i = 1; i < dmin; ++i) {
		sum *= pow(2, 2 * i);
	}
	int temp = dmax - dmin;
	for (int i = 0; i <= temp; ++i) {
		sum *= pow(2, dmin);
	}
	cout << "共有" << sum << "种路径。" << endl;
	return 0;
>>>>>>> 431476fb7a89386c4eb9cd41bd20f2b7ee2dbc09
}