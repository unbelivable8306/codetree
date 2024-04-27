#include <iostream>
using namespace std;
int main() {
    int n;
    int cnt = 0;
    for(int i=0;i<10;i++){
        cin >> n;
        if(i%2 ==1) cnt += 1;
    }
    cout << cnt;
    return 0;
}