#include <iostream>
using namespace std;
int cnt[11], a, b, c, d;
int sum = 0;
int main() {
	cin >> a >> b;
	for (int i = 1; i <= 20; i++) {
		c = a % b;
		d = a / b;
		cnt[c]++;
		a /= b;
		if (d == 0) break;
	}

	for (int i = 0; i < b; i++) {
		sum += cnt[i] * cnt[i];
	}
	cout << sum;
	
}