#include <iostream>
using namespace std;
int a[100];
int sum = 0;
int cnt = 0;
int main() {
	for (int i = 0; i < 100; i++) {
		cin >> a[i];
		if (a[i] == 0 && cnt==0) {
			cout << a[i - 3] + a[i - 2] + a[i - 1];
			cnt++;
		}
		
	}
}