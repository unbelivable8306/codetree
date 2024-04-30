#include <iostream>
using namespace std;
int main() {
	int a;
	int cnt = 0;
	while (1) {
		cin >> a;
		if (a % 2 == 0) {
			a /= 2;
			cout << a << endl;;
			cnt++;
		}
		if (cnt == 3) break;
	}
		
	
	return 0;
}