#include <iostream>
using namespace std;
double sum = 0;
int cnt = 0;
double avr, a[10];
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		cnt++;
		if (a[i] == 0) {
			cnt--;
			break;
		}
	}
	for (int i = cnt; i > 0; i--) {
		cout << a[i - 1] << " ";
	}
	
}