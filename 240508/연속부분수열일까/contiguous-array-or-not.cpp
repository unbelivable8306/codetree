#include <iostream>
using namespace std;
int n1, n2,fin_cnt;
int a[100], b[100];
bool tag = false;
int main() {
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n1; i++) {
        int index = 1;
        int cnt = 1;
        int index2 = i;
        if (b[0] == a[i]) {
            while (b[index] != 0) {
                if (b[index] == a[index2 + 1]) {
                    cnt++;
                }
                index2++;
                index++;
            }
            if (cnt == n2) tag = true;
        }
   }
    if (tag == true) cout << "Yes";
    else cout << "No";
    return 0;
}