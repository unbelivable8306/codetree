#include <iostream>
using namespace std;
int sum = 0;
int cnt = 0;
int a[10];
double avr;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			break;
		}
		else if (a[i] % 2 == 0) {
			cnt++;
			sum += a[i];
		}
	}
	cout << fixed;
	cout.precision(1);
	cout << cnt << ' ' << sum;
}