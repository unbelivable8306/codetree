#include <iostream>
using namespace std;
int a[10];
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	cout << a[2] + a[4] + a[9];
}