#include <string>
#include <vector>

using namespace std;

int fibonacci(int n, int p, int pp) {
    // int 범위 넘어가는 거 방지(조건에 있는 수)
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