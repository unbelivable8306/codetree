#include <iostream>
using namespace std;
int index;
int n, m, cnt;
int a[100];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == m) cnt++;
	}
	cout << cnt;
}