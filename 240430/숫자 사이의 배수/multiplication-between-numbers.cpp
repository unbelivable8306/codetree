#include <iostream>
using namespace std;
int main() {
	int a, b;
	int sum = 0;
	int cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % 5 == 0 || i % 7 == 0) {
			sum += i;
			cnt += 1;
		}
	}
	cout << sum << " ";
	cout << fixed;
	cout.precision(1);
	cout << (double)sum / cnt;
	return 0;
}