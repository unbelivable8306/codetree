#include <iostream>
using namespace std;
int main() {
    int count = 0;
    int a;
    for(int i = 1; i <=5 ; i++){
        cin >> a;
        if(a % 2 == 0){
            count += 1;
        }
    }
    cout << count;
    return 0;
}