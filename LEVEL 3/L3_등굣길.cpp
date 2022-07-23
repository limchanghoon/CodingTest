#include <string>
#include <vector>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // 오른쪽으로 그리고 아래쪽으로 한칸씩 더 만들어서 0으로 채운다.(계산의 편의를 위해)
    int** board = new int* [m + 1];
    for (int i = 0; i < m + 1; i++) {
        board[i] = new int[n + 1]();
    }

    // 웅덩이 표시
    for (int i = 0; i < puddles.size(); i++) {
        board[puddles[i][0] - 1][puddles[i][1] - 1] = -1;
    }
    board[m - 1][n - 1] = 1;

    // 불가능한 경우
    if (board[m - 1][n - 2] == -1 && board[m - 2][n - 1] == -1) {
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1)
                continue;
            if (board[j][i] == -1) {
                board[j][i] = 0;
            }
            else {
                board[j][i] = (board[j + 1][i] + board[j][i + 1]) % 1000000007;
            }
        }
    }

    answer = board[0][0];
    return answer;
}

int main() {
    solution(4, 3, { { 2, 2 } });

    return 0;
}