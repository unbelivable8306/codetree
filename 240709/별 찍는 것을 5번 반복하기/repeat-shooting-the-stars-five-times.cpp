#include <iostream>
using namespace std;
void print_star() {
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 10; i++) {
            cout << '*';
        }
        cout << endl;
    }
}
int main() {
    print_star();
    return 0;
}