#include <iostream>
using namespace std;
int main() {
	int n;
	int sum = 0;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum == n) {
		cout << 'P';
	}
	else cout << 'N';
	return 0;
}