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

    // 목적지에서 각 노드까지의 비용
    int* costs = new int[n+1];
    fill_n(costs, n+1, -1);
    costs[destination] = 0;

    // 각 간선은 왕복이다.
    // 인덱스가 가능하게 변경
    vector<vector<int>> a(n+1);
    for (vector<int> i : roads) {
        a[i[0]].push_back(i[1]);
        a[i[1]].push_back(i[0]);
    }

    // 목적지부터 하나씩 간선을 타고 방문
    // 그전에 방문한 곳이면 cost를 비교해 낮으면 재방문
    // 방문시 큐에 넣는다.
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

    // -1이면 costs값이 변경되지 않은 것 == 방문 가능하지 않은 곳이다.
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