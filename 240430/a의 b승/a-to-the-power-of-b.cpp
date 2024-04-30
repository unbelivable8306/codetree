#include <iostream>
using namespace std;
int main() {
	int a, b;
	int cnt = 0;
	int prod = 1;
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		prod *= a;
	}
	cout << prod;
	return 0;
}