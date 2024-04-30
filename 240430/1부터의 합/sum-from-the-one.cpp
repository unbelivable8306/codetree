#include <iostream>
using namespace std;
int main() {
	int n;
	int sum = 0;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
		cnt++;
		if (sum >= n) break;
	}
	cout << cnt;
	return 0;
}