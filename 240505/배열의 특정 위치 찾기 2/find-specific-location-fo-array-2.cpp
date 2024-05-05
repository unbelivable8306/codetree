#include <iostream>
using namespace std;
int a[10];
int sum1 = 0, sum2 = 0;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		if (i % 2 == 0) sum1 += a[i];
		else sum2 += a[i];
	}
	if (sum1 > sum2) cout << sum1 - sum2;
	else cout << sum2 - sum1;
}