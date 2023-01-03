/*

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Nord {
public:
    int cost = -1;
    
    Nord() : cost(0) {}
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {

    // ���������� �� �������� ���
    int* costs = new int[n+1];
    fill_n(costs, n+1, -1);
    costs[destination] = 0;

    // �� ������ �պ��̴�.
    // �ε����� �����ϰ� ����
    vector<vector<int>> a(n+1);
    for (vector<int> i : roads) {
        a[i[0]].push_back(i[1]);
        a[i[1]].push_back(i[0]);
    }

    // ���������� �ϳ��� ������ Ÿ�� �湮
    // ������ �湮�� ���̸� cost�� ���� ������ ��湮
    // �湮�� ť�� �ִ´�.
    queue<int> q;
    q.push(destination);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (int i : a[pos]) {
            if (costs[i] == -1 || costs[i] > costs[pos] + 1) {
                costs[i] = costs[pos] + 1;
                q.push(i);
            }
        }
    }

    // -1�̸� costs���� ������� ���� �� == �湮 �������� ���� ���̴�.
    vector<int> answer;
    for (int i : sources) {
        answer.push_back(costs[i]);
    }

    return answer;
}

int main() {
    vector<int> v = solution(5, { {1,2}, {1,4}, {2,4}, {2,5}, {4,5} }, {1,3,5}, 5);
    printf("%d, %d, %d\n", v[0], v[1], v[2]);
    return 0;
}

*/