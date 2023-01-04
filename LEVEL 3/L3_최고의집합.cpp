/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    // n�� s���� ũ�� �Ұ���
    if (n > s)
        return { -1 };

    vector<int> answer;
    // ��� ���� �����ϰ� ũ�� �ȴ�. ���� ��� 11�� 4���� �ϸ� => 2 3 3 3
    // s%n�� �� x��� ����.
    // n-x���� s/n �̰� x���� s/n + 1�̴�. n=4, s=11�̶�� ����
    // x = 3, n-x = 1, s/n = 2, s/n + 1 = 3
    // �� 2 3 3 3�� �ȴ�.
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