#include <iostream>
using namespace std;
int a[100];
int n;
int main() {
	cin >> n;
	int prev = 1;
	int cnt = 0;
	while (cnt < 2) {
		cout << n * prev << " ";
		if ((n*prev) % 5 == 0) {
			cnt++;
		}
		prev++;
	}
}