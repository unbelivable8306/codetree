#include <iostream>
using namespace std;
int a[100];
int cnt = 0;
int n;
int main() {
	for (int i = 0; i < 2; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 8; i++) {
		a[i + 2] = a[i + 1] + 2 * a[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}