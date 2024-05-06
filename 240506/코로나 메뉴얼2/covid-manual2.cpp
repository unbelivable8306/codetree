#include <iostream>
using namespace std;
int temp, cnt[5];
int cnt_Y = 0;
char check;
int main() {
	for (int i = 1; i <= 3; i++) {
		cin >> check >> temp;
		if (check == 'Y' && temp >= 37) {
			cnt[1]++;
			cnt_Y++;
		}
		else if (check == 'N' && temp >= 37) {
			cnt[2]++;
		}
		else if (check == 'Y' && temp < 37) {
			cnt[3]++;
		}
		else if (check == 'N' && temp < 37) {
			cnt[4]++;
		}
	}
	if (cnt_Y >= 2) {
		for (int i = 1; i <= 4; i++) {
			cout << cnt[i] << " ";
		}
		cout << 'E';
	}
	else {
		for (int i = 1; i <= 4; i++) {
			cout << cnt[i] << " ";
		}
	}

}