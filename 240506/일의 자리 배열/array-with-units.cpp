#include <iostream>
using namespace std;
int a[10];
int main() {
	for (int i = 0; i < 2; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 8; i++) {
		a[i + 2] = (a[i] + a[i + 1]) % 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}