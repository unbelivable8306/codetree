#include <iostream>
using namespace std;
int sum;
int cnt = 0;
int n;
int a[4];
double avr;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a[j];
			sum += a[j];
			avr = (double)sum / 4;
		}
		if (avr >= 60) {
			cout << "pass" << endl;
			cnt++;
		}
		else cout << "fail" << endl;
	}
	cout << cnt;
}