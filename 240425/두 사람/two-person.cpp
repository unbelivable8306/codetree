#include <iostream>
using namespace std;
int main() {
    int a,b;
    char a_name, b_name;
    cin >> a >> a_name;
    cin >> b >> b_name;
    if(a_name == 'M' || b_name == 'M') cout << "1";
    else cout << "0";
    return 0;
}