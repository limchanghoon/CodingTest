#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> v(5001);

int solution(int n) {
    if (n % 2 == 1)
        return 0;
    v[2] = 3;
    v[4] = 11;
    for (size_t i = 6; i <= n; i += 2) {
        //  v[i - 2] - v[i - 4]가 음수가 나올 수 있어서 1000000007을 더해준다.
        v[i] = (1000000007 + 4 * v[i - 2] - v[i - 4]) % 1000000007;
    }
    return v[n];
}

int main() {
    cout << solution(2) << endl;
    cout << solution(4) << endl;
    cout << solution(6) << endl;
    cout << solution(8) << endl;
    return 0;
}