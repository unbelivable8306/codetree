#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if(3 <= n && n <= 5) cout << "Spring";
    else if(6 <= n && n <= 8) cout << "Summer";
    else if(9 <= n && n <= 11) cout << "Fall";
    else cout << "Winter";
    return 0;
}