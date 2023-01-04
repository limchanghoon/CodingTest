/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    // n이 s보다 크면 불가능
    if (n > s)
        return { -1 };

    vector<int> answer;
    // 모든 수가 균일하게 크면 된다. 예를 들어 11을 4개로 하면 => 2 3 3 3
    // s%n개 를 x라고 하자.
    // n-x개는 s/n 이고 x개는 s/n + 1이다. n=4, s=11이라고 가정
    // x = 3, n-x = 1, s/n = 2, s/n + 1 = 3
    // 즉 2 3 3 3이 된다.
    for (int i = 0; i < n - s % n; i++) {
        answer.push_back(s / n);
    }
    for (int i = 0; i < s % n; i++) {
        answer.push_back(s / n + 1);
    }
    return answer;
}

int main() {
    vector<int> v = solution(3, 11);
    printf("%d, %d, %d\n", v[0], v[1], v[2]);
    return 0;
}
*/