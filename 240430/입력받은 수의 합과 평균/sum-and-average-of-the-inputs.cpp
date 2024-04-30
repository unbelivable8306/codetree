#include <iostream>
using namespace std;
int main() {
	int n,a;
	int sum = 0;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		sum += a;
		cnt += 1;
	}
	cout << sum << " ";
	cout << fixed;
	cout.precision(1);
	cout << (double)sum / cnt;
	return 0;
}