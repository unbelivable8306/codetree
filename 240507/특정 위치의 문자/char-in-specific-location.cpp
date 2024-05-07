#include <iostream>
using namespace std;
int index;
char m;
char a[6] = { 'L','E','B','R','O','S' };
int main() {
	cin >> m;
	if (m == 'L') cout << 0;
	else if (m == 'E') cout << 1;
	else if (m == 'B') cout << 2;
	else if (m == 'R') cout << 3;
	else if (m == 'O') cout << 4;
	else if (m == 'O') cout << 5;
	else cout << "None";
}