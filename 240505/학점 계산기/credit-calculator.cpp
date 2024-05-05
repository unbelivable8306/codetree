#include <iostream>
using namespace std;
double sum = 0;
int n;
double avr, a[5];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	avr = (double)sum / n;
	cout << fixed;
	cout.precision(1);
	cout << avr << endl;
	if (avr >= 4.0) cout << "Perfect";
	else if (avr >= 30) cout << "Good";
	else cout << "Poor";
}