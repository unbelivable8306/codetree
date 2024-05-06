#include <iostream>
using namespace std;
int a[100];
int cnt = 0;
int n;
int main() {
	cin >> n;
	a[0] = 1;
	a[1] = n;
	for (int i = 0; i < 100; i++) {
		a[i + 2] = a[i + 1] + a[i];
		cnt++;
		if (a[i + 2] > 100) break;
	}
	for (int i = 0; i < cnt + 2; i++) {
		cout << a[i] << " ";
	}
}