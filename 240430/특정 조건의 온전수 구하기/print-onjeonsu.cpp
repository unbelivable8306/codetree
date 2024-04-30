#include <iostream>
using namespace std;
int main() {
	int n;
	int cnt = 0;
	int prod = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) continue;
		else if (i % 10 == 5) continue;
		else if (i % 3 == 0 && i % 9 != 0) continue;
		else cout << i << " ";
	}
	return 0;
}