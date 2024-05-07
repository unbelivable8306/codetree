#include <iostream>
using namespace std;
int n, q;
int a[100];
int input[3];
bool tag = false;
int p, s, r, index;
int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> p;
		if (p == 1) {
			cin >> s;
			cout << a[s - 1] << endl;
		}
		if (p == 2) {
			cin >> s;
			for (int i = 0; i < n; i++) {
				if (a[i] == s) {
					index = i+1;
					tag = true;
					break;
				}
			}
			if (tag == false) cout << 0 << endl;
			else if(tag == true) cout << index << endl;
		}
			
		}
		if (p == 3) {
			cin >> s >> r;
			for (int i = s-1; i <= r-1; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}