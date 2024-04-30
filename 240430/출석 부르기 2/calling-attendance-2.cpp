#include <iostream>
using namespace std;
int main() {
	int a;
	while (1) {
		cin >> a;
		if (a == 1) cout << "John" << endl;
		else if (a == 2) cout << "Tom" << endl;
		else if (a == 3) cout << "Paul" << endl;
		else if (a == 4) cout << "Sam" << endl;
		else {
			cout << "Vacancy";
			break;
		}
		}
	
	return 0;
}