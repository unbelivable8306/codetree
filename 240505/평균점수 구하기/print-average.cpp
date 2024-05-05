#include <iostream>
using namespace std;
double sum = 0;
double avr, a[8];
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
		sum += a[i];
	}
	avr = (double)sum / 8;
	cout << fixed;
	cout.precision(1);
	cout << avr << endl;
	
}