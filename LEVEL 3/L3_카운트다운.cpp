/*
#include <string>
#include <vector>

#define pointSize 42

using namespace std;

// 1~20�� �̱�, 50�� ��
const int points[pointSize] = {
    1,2,3,4,5,6,7,8,9,10,
    11,12,13,14,15,16,17,18,19,20,
    21,22,24,26,27,28,30,
    32,33,34,36,38,39,40,
    42,45,48,50,
    51,54,57,60
};

vector<int> solution(int target) {
    // ���� ��Ʈ ���� �ϳ��� �����ϴ� ��츦 �� �־��ش�.
    vector<vector<int>> v(target+1);
    for (int i : points) {
        if (i > target)
            break;
        v[i].push_back(1);
        // Ư�� 1~20 �� 50�� "�̱�" �Ǵ� "��"�� ���� Ƚ���� 1������Ų��. ���������� 0
        if ((1 <= i && i <= 20) || i == 50) {
            v[i].push_back(1);
            continue;
        }
        v[i].push_back(0);
    }

    // �ϳ��� �����ϴ� ��츦 ���� i�� �����ϰ� ����� ���� ������� �۴ٸ� �����Ѵ�.
    // i�� target���� �����ϸ鼭 ���� ��ȹ���� ����Ѵ�.
    for (int i = 1; i <= target; i++) {
        for (int j : points) {
            if (i + j > target)
                break;
            int count = v[i][0] + v[j][0];
            int SB = v[i][1] + v[j][1];
            if (v[i + j].empty()) {
                v[i + j].push_back(count);
                v[i + j].push_back(SB);
            }
            else {
                if (v[i + j][0] == count && v[i + j][1] < SB) {
                    v[i + j][1] = SB;
                }
                else if (v[i + j][0] > count) {
                    v[i + j][0] = count;
                    v[i + j][1] = SB;
                }
            }
        }
    }
    return { v[target][0] , v[target][1] };
}

int main() {
    vector<int> v = solution(61);

    printf("%d, %d\n", v[0], v[1]);
    return 0;
}

*/