#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int count = 1;
    while (A < B) {
        if (B % 10 == 1)
            B /= 10;
        else if (B % 2 == 0)
            B /= 2;
        else {
            cout << -1 << endl;
            return 0;
        }
        count++;
    }

    if (A == B)
        cout << count << endl;
    else
        cout << -1 << endl;

    return 0;
}