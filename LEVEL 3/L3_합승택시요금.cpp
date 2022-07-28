#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 20000001;
    // 0은 비우고 인덱스 1 ~ n까지 사용
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 20000001));
    for (int i = 1; i <= n; i++) {
        v[i][i] = 0;
    }
    for (int i = 0; i < fares.size(); i++) {
        v[fares[i][0]][fares[i][1]] = fares[i][2];
        v[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && j != k && i != k) {
                    if (v[j][k] > v[j][i] + v[i][k])
                        v[j][k] = v[j][i] + v[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (answer > v[s][i] + v[i][a] + v[i][b])
            answer = v[s][i] + v[i][a] + v[i][b];
    }

    return answer;
}

/*
int main() {

    printf("Result : %d\n", solution(7, 3, 4, 1, { {5, 7, 9},{4, 6, 4},{3, 6, 1},{3, 2, 3},{2, 1, 6} }));
}
*/