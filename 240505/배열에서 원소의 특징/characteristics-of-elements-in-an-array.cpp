#include <iostream>
using namespace std;
int a[10];
int cnt = 0;
int sum1 = 0, sum2 = 0;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		if (a[i] % 3 == 0 && cnt == 0) {
			cout << a[i - 1];
			cnt++;
	    }
    }
}