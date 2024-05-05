#include <iostream>
using namespace std;
char a[10];
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	cout << a[1] << " " <<  a[4] << " " << a[7];
}