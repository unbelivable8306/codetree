#include <iostream>
using namespace std;
int a[10];
int sum1= 0;
int sum2 = 0;
int cnt = 0;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 0; i+1 < 10; i+=2) {
		sum1+= a[i+1];
	}
	for (int i = 0; i+2 < 10; i += 3) { // 2 5 8
		sum2 += a[i + 2];
		cnt++;
	}
	cout << fixed;
	cout.precision(1);
	cout << sum1 << " "<< (double)sum2 / cnt;
}