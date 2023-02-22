#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for (int n : tangerine) {
        if (!m.insert({ n,1 }).second) {
            m[n]++;
        }
    }
    vector<pair<int, int>> v;
    for (auto& it : m) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(),cmp);
    for (size_t i = 0; i < v.size(); i++) {
        k -= v[i].second;
        answer++;
        if (k <= 0)
            break;
    }
    return answer;
}

int main() {
    cout << "문제1 정답 : " << solution(6, { 1, 3, 2, 5, 4, 5, 2, 3 }) << endl;
    cout << "문제2 정답 : " << solution(4, { 1, 3, 2, 5, 4, 5, 2, 3 }) << endl;
    cout << "문제3 정답 : " << solution(2, { 1, 1, 1, 1, 2, 2, 2, 3 }) << endl;
    return 0;
}