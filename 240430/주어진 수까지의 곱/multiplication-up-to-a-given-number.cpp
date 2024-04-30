#include <iostream>
using namespace std;
int main() {
	int a, b;
	int prod = 1;
	int cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		prod *= i;
	}
	cout << prod;
	return 0;
}