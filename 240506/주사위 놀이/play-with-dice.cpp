#include <iostream>
using namespace std;
int a[10], cnt[10];
int n;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= 6; i++) {
		cout << i << " - " << cnt[i] << endl;
	}
}