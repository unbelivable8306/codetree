#include <iostream>
using namespace std;
int a[10], cnt[10];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i] - 1]++;
	}
	for (int i = 0; i < 9; i++) {
		cout << cnt[i] << endl;
	}
}