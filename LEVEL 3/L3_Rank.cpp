/*

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<set<int>> uv;
vector<set<int>> dv;

void US(int root, int point, bool* visited) {
    for (auto iter = uv[point].begin(); iter != uv[point].end(); iter++) {
        if (visited[*iter])
            continue;

        visited[*iter] = true;
        uv[root].insert(*iter);
        US(root, *iter, visited);
    }
}

void DS(int root, int point, bool* visited) {
    for (auto iter = dv[point].begin(); iter != dv[point].end(); iter++) {
        if (visited[*iter])
            continue;

        visited[*iter] = true;
        dv[root].insert(*iter);
        DS(root, *iter, visited);
    }
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 0; i < n + 1; i++) {
        set<int> tv = {0};
        uv.push_back(tv);
        dv.push_back(tv);
    }

    for (int i = 0; i < results.size(); i++) {
        uv[results[i][1]].insert(results[i][0]);
        dv[results[i][0]].insert(results[i][1]);
    }
    bool* Visited = new bool[n + 1];
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            Visited[j] = false;
        }
        Visited[i] = true;
        US(i, i, Visited);
        DS(i, i, Visited);
    }

    for (int i = 1; i < n + 1; i++) {

        int x = uv[i].size() + dv[i].size();
        if (x == n + 1)
            answer++;
    }

    return answer;
}

int main() {
    vector<vector<int>> v1;
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(3);
    v1.push_back(v2);
    v2.clear();

    v2.push_back(4);
    v2.push_back(2);
    v1.push_back(v2);
    v2.clear();

    v2.push_back(3);
    v2.push_back(2);
    v1.push_back(v2);
    v2.clear();

    v2.push_back(1);
    v2.push_back(2);
    v1.push_back(v2);
    v2.clear();

    v2.push_back(2);
    v2.push_back(5);
    v1.push_back(v2);
    v2.clear();

    printf("%d\n", solution(5, v1));
    return 0;
}

*/