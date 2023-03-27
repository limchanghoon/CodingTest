#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v(60001);

int solution(int n) {
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i - 1] + v[i - 2])% 1000000007;
    }
    return v[n];
}

int main() {
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;

    return 0;
}