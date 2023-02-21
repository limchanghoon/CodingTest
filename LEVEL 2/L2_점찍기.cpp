#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long d_square = pow(d, 2);
    for (size_t height = 0; height <= d; height += k) {
        int x = static_cast<int>(sqrt(d_square - pow(height, 2)));
        answer += (x / k + 1);
    }
    return answer;
}

int main() {
    cout << "케이스1 정답 : " << solution(2,4) << endl;
    cout << "케이스2 정답 : " << solution(1,5) << endl;
    return 0;
}