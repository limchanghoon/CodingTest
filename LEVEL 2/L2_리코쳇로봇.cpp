#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    queue<pair<int, int>> q;
    vector<vector<int>> v(board.size(), vector<int>(board[0].size(), INT_MAX));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R') {
                q.push({ i,j });
                v[i][j] = 0;
                i = board.size();
                break;
            }
        }
    }

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        int cnt = v[pos.first][pos.second];

        if (board[pos.first][pos.second] == 'G') {
            answer = v[pos.first][pos.second];
            break;
        }
        
        // ╩С
        for (int i = pos.first; i >= 0; i--) {
            if (i == 0 || (i - 1 >= 0 && board[i - 1][pos.second] == 'D')) {
                if (v[i][pos.second] > cnt + 1) {
                    v[i][pos.second] = cnt + 1;
                    q.push({ i,pos.second });
                }
                break;
            }
        }

        // го
        for (int i = pos.first; i < board.size(); i++) {
            if (i == board.size()-1 || (i + 1 < board.size() && board[i + 1][pos.second] == 'D')) {
                if (v[i][pos.second] > cnt + 1) {
                    v[i][pos.second] = cnt + 1;
                    q.push({ i,pos.second });
                }
                break;
            }
        }

        // аб
        for (int i = pos.second; i >= 0; i--) {
            if (i == 0 || (i - 1 >= 0 && board[pos.first][i - 1] == 'D')) {
                if (v[pos.first][i] > cnt + 1) {
                    v[pos.first][i] = cnt + 1;
                    q.push({ pos.first, i });
                }
                break;
            }
        }

        // ©Л
        for (int i = pos.second; i < board[0].size(); i++) {
            if (i == board[0].size() - 1 || (i + 1 < board[0].size() && board[pos.first][i + 1] == 'D')) {
                if (v[pos.first][i] > cnt + 1) {
                    v[pos.first][i] = cnt + 1;
                    q.push({ pos.first, i });
                }
                break;
            }
        }

    }


    return answer;
}

int main() {
    cout << solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." }) << endl;
    cout << solution({ ".D.R", "....", ".G..", "...D" }) << endl;

    return 0;
}