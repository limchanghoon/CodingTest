#include <string>
#include <vector>

using namespace std;

int fibonacci(int n, int p, int pp) {
    // int ���� �Ѿ�� �� ����(���ǿ� �ִ� ��)
    p %= 1234567;
    pp %= 1234567;
    if (n <= 1) {
        return p;
    }
    else {
        return fibonacci(--n, p + pp, p);
    }
}

int solution(int n) {
    int answer = fibonacci(n, 1, 0);
    return answer;
}

int main() {
    printf("%d\n", solution(3));
    printf("%d\n", solution(5));
    return 0;
}