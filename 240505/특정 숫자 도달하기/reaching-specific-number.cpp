#include <iostream>
using namespace std;
int a[10];
int sum = 0, cnt = 0;
double avr;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		if (a[i] >= 250) {
			break;
		}
		else {
			sum += a[i];
			cnt++;
		}
	}
	avr = (double)sum / cnt;
	cout << fixed;
	cout.precision(1);
	cout << sum << " " << avr;
}