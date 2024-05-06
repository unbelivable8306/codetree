#include <iostream>
using namespace std;
int a[10];
int cnt = 0;
int n;
int sum1 = 0, sum2 = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i]*a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}