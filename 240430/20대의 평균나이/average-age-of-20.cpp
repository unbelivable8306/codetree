#include <iostream>
using namespace std;
int main() {
	int a;
	int sum = 0;
	int cnt = 0;
	while (1) {
		cin >> a;
		if (20 <= a && a <= 29) {
			sum += a;
			cnt++;
		}
		else break;
	}
	cout << fixed;
	cout.precision(2);
	cout << (double)sum / cnt;
	
	return 0;
}