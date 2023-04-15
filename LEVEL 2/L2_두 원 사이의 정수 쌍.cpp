#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long rr2 = (long)r2 * (long)r2;
    long rr1 = (long)r1 * (long)r1;
    for (long i = 0; i < r2; i++) {
        long ii = (long)i * (long)i;
        if (i < r1) {
            answer += floor(sqrt(rr2 - ii)) - ceil(sqrt(rr1 - ii)) + 1;
        }
        else {
            answer += floor(sqrt(rr2 - ii));
        }
    }
    return answer*4;
}

int main() {
    cout << solution(2,3) << endl;
    return 0;
}