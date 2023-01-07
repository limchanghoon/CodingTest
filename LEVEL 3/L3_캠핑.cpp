#include <vector>
#include <algorithm>

using namespace std;

// ���� ������ �ε��� 0�� �������� �������� ������ �Ѵ�. �ε��� 0�� ���� ��� �ε��� 1�� �������� �������� ������ �Ѵ�.
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}



// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end(), cmp);
    for (int i = 0; i < n; i++) {
        // ��ǥ �ϳ��� �˻��Ѵ�.

        // ���� for���� ���鼭 üũ�ϰ� �ִ� X��ǥ
        int curX = data[i][0];
        
        // �¿� ��ǥ �ִ밪���� �ʱ�ȭ, �ش� ������ ������ ��ǥ�� üũ��.
        int right = 2147483647;
        int left = 0;

        // ���� for������ üũ�ϴ� X��ǥ�� �����ϸ� preRight�� preLeft�� right�� left�� �ӽ� ������.
        int preRight = 2147483647;
        int preLeft = 0;

        // ���� ��ǥ(���ü��� ����)
        int startX = data[i][0];
        int startY = data[i][1];


        for (int j = i; j < n; j++) {
            if (curX < data[j][0]) {
                preRight = right;
                preLeft = left;
                curX = data[j][0];
            }

            if (startX != data[j][0] && startY != data[j][1]) {
                if (preLeft <= data[j][1] && data[j][1] < startY) {
                    answer++;
                    if (left < data[j][1]) {
                        left = data[j][1];
                    }
                }
                if (data[j][1] <= preRight && startY < data[j][1]) {
                    answer++;
                    if (data[j][1] < right) {
                        right = data[j][1];
                    }
                }
            }

        }
    }

    return answer;
}

/*
int main() {
    //vector<vector<int>> v = { {0, 0}, {1, 1}, {0, 2}, {2, 0} };
    vector<vector<int>> v = { {0, 0}, {0, 2}, {1, 1}, {1, 3},{1, 4}, {2, 0}, {2, 2}, {3, 2}, {4, 3} };
    printf("result : %d\n", solution(v.size(), v));
    return 0;
}

*/