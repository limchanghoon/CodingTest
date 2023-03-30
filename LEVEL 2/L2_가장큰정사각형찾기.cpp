#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    vector<vector<int>> v(board.size() + 1, vector<int>(board[0].size() + 1));
    for (int i = 1; i < v.size(); i++) {
        for (int j = 1; j < v[0].size(); j++) {
            if (board[i - 1][j - 1] == 1) {
                v[i][j] = min({ v[i - 1][j], v[i][j - 1], v[i - 1][j - 1] }) + 1;
                answer = max(answer, v[i][j]);
            }
        }
    }

    return answer * answer;
}

int main() {
    cout << solution({ {0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,0,1,0} }) << endl;
    cout << solution({ {0,0,1,1}, {1,1,1,1} }) << endl;

    return 0;
}