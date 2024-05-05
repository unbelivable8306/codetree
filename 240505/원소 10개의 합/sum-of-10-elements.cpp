#include <iostream>
using namespace std;
int a;
int sum=0;
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> a;
		sum += a;
	}
	cout << sum;

}