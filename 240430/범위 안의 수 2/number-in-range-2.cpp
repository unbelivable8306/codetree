#include <iostream>
using namespace std;
int main() {
	int a;
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= 10; i++) {
		cin >> a;
		if (0 <= a && a <= 200) {
			sum += a;
			cnt += 1;
		}
	}
	cout << sum << " ";
	cout << fixed;
	cout.precision(1);
	cout << (double)sum / cnt;
	return 0;
}