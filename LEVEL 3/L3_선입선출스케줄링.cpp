#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    if (cores.size() >= n) {
        return n;
    }

    // 이진탐색 상한값 구하기(조건에 나와있는 최대의 경우 고정할 시 효율성 통과못함...)
    int max = 0;
    for (int i = 0; i < cores.size(); i++) {
        if (max < cores[i])
            max = cores[i];
    }

    // 이진탐색으로 완료되는 시간 혹은 그 바로전 시간을 구함
    int current;
    int up = max*n;
    int down = 0;
    while (true) {
        int tmp = cores.size();
        int mid = (up + down) / 2;
        for (int i = 0; i < cores.size(); i++) {
            tmp += mid / cores[i];
        }
        if (tmp >= n) {
            up = mid;
        }
        else {
            down = mid;
        }
        if (down + 1 == up) {
            current = down - 1;
            break;
        }
    }

    // 이진탐색으로 구한 시간까지 처리한 작업 수 구하기
    int cnt = cores.size();
    for (int i = 0; i < cores.size(); i++) {
        cnt += current / cores[i];
    }

    // 이진탐색으로 구한 시간부터 하나씩 작업을 넣어서 마지막을 찾음
    while (true) {
        current++;
        for (int i = 0; i < cores.size(); i++) {
            if (current % cores[i] == 0) {
                if (++cnt == n) {
                    return i + 1;
                }
            }
        }
    }
}

int main() {
    printf("%d\n", solution(6, {1,2,3}));
    return 0;
}