#include <iostream>
using namespace std;
int cnt[10], a, b, c, d;
int sum = 0;
int main() {
	cin >> a >> b;
	for (int i = 1; i <= 10; i++) {
		c = a % b;
		d = a / b;
		cnt[c]++;
		a /= b;
		if (a<=1) break;
	}

	for (int i = 0; i <= 9; i++) {
		sum += cnt[i] * cnt[i];
	}
	cout << sum;
	
}