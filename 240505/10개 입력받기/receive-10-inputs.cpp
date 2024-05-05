#include <iostream>
using namespace std;
int sum = 0;
int cnt = 0;
double avr, a[10];
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		cnt++;
		if (a[i] == 0) {
			cnt--;
			break;
		}
		else sum += a[i];
	}
	cout << fixed;
	cout.precision(1);
	cout << sum << ' ' << (double)sum / cnt;
}