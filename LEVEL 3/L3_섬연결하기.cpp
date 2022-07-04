#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    bool* check = new bool[n];

    for (int i = 0; i < n; i++) {
        check[i] = false;
    }

    sort(costs.begin(), costs.end(), cmp);
    check[costs[0][0]] = true;
    check[costs[0][1]] = true;
    answer += costs[0][2];

    bool notEnd = true;

    while (notEnd) {
        for (int i = 0; i < costs.size(); i++) {
            if ( (!check[costs[i][0]] && check[costs[i][1]]) || (check[costs[i][0]] && !check[costs[i][1]]) ) {
                check[costs[i][0]] = true;
                check[costs[i][1]] = true;
                answer += costs[i][2];

                printf("i = %d, (%d,%d), cost = %d\n", i, costs[i][0], costs[i][1], costs[i][2]);
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!check[i])   break;
            if (i == n - 1)    notEnd = false;
        }
    }
    return answer;
}


int main() {
    vector<vector<int>> v;
    v.push_back({ 0,1,1 });
    v.push_back({ 0,2,2 });
    v.push_back({ 1,2,5 });
    v.push_back({ 1,3,1 });
    v.push_back({ 2,3,8 });
    printf("result : %d\n",solution(4,v));
}