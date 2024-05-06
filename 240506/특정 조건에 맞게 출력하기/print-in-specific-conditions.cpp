#include <iostream>
using namespace std;
int a[100];
int cnt = 0;
int main() {
	for (int i = 0; i < 100; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			a[i] += 3;
			cnt++;
		}
		else if (a[i] % 2 == 0 && a[i] !=0) {
			a[i] /= 2;
			cnt++;
		}
		if (a[i] == 0) break;
	}
	for (int i = 0; i < cnt; i++) {
		cout << a[i] << " ";
	}
	
}