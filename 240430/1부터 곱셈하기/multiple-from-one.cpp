#include <iostream>
using namespace std;
int main() {
	int n;
	int prod = 1;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= 10; i++) {
		prod *= i;
		cnt++;
		if (prod >= n) break;
	}
	cout << cnt;
	return 0;
}