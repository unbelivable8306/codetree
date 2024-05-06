#include <iostream>
using namespace std;
int a[100], cnt[100];
int n;
int main() {
	for (int i = 0; i < 100; i++) {
		cin >> a[i];
		cnt[a[i]/10]++;
		if (a[i] == 0) break;
	}
	for (int i = 100; i >= 10; i-=10) {
		cout << i << " - " << cnt[i/10] << endl;
	}
}