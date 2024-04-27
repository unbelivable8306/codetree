#include <iostream>
using namespace std;
int main() {
    int n;
    int cnt = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(i%4==0){
            if(i%100==0) continue;
            else if(i%400==0) cnt++;
            else cnt++; 
        }
    }
    cout << cnt;
    return 0;
}