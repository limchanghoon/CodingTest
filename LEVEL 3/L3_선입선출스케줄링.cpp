#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    if (cores.size() >= n) {
        return n;
    }

    // ����Ž�� ���Ѱ� ���ϱ�(���ǿ� �����ִ� �ִ��� ��� ������ �� ȿ���� �������...)
    int max = 0;
    for (int i = 0; i < cores.size(); i++) {
        if (max < cores[i])
            max = cores[i];
    }

    // ����Ž������ �Ϸ�Ǵ� �ð� Ȥ�� �� �ٷ��� �ð��� ����
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

    // ����Ž������ ���� �ð����� ó���� �۾� �� ���ϱ�
    int cnt = cores.size();
    for (int i = 0; i < cores.size(); i++) {
        cnt += current / cores[i];
    }

    // ����Ž������ ���� �ð����� �ϳ��� �۾��� �־ �������� ã��
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