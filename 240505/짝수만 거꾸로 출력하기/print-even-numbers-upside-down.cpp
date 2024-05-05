#include <iostream>
using namespace std;
int sum;
int cnt = 0;
int n;
int a[100];
double avr;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 0; i--) {
		if (a[i-1] % 2 == 0) {
			cout << a[i - 1] << " ";
		}
	}
}