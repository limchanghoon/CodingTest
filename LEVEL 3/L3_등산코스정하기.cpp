#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> aligned_paths;
int gates_c[50001];
int summits_c[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    sort(summits.begin(), summits.end());
    aligned_paths.resize(n + 1);

    for (int g : gates) {
        gates_c[g] = 1;
    }
    for (int s : summits) {
        summits_c[s] = 1;
    }

    for (vector<int> p : paths) {
        aligned_paths[p[0]].push_back({ p[1],p[2] });
        aligned_paths[p[1]].push_back({ p[0],p[2] });
    }

    queue<pair<int, int>> q;
    vector<int> costs(n + 1, INT_MAX);
    for (int g : gates) {
        for (auto v : aligned_paths[g]) {
            q.push({ v[0],v[1] });
        }
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (costs[node.first] <= node.second || gates_c[node.first] == 1)
            continue;

        costs[node.first] = node.second;

        if (summits_c[node.first] == 1)
            continue;

        for (vector<int> v : aligned_paths[node.first]) {
            q.push({ v[0], max(v[1], node.second) });
        }
    }

    int result_cost = INT_MAX;
    int result_point = INT_MAX;
    for (int s : summits) {
        if (result_cost > costs[s]) {
            result_cost = costs[s];
            result_point = s;
        }
    }

    return { result_point, result_cost };
}

// 출입구, 쉼터, 혹은 산봉우리
// 휴식 없이 이동해야 하는 시간 중 가장 긴 시간을 해당 등산코스의 intensity => 최소로 갖기
// 출입구 => 산봉우리 => 원래의 출입구
// 사실 출입구 => 산봉우리만 계산하면 된다!

int main() {
    auto v = solution(6, { { 1,2,3 },{2,3,5},{2,4,2},{2,5,4},{3,4,4},{4,5,3},{4,6,1},{5,6,1} }, { 1,3 }, { 5 });
    for (int r : v) {
        cout << r << ", ";
    }
    cout << endl;
}