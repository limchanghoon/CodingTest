#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 0 1 2
// 3 4 5
// 6 7 8
vector<vector<int>> patterns = {
    { 0,1,2 },
    { 3,4,5 },
    { 6,7,8 },
    { 0,3,6 },
    { 1,4,7 },
    { 2,5,8 },
    { 0,4,8 },
    { 2,4,6 }
};

bool check_win(vector<string>& board, const char chr) {
    for (const vector<int>& v : patterns) {
        if ((board[v[0] / 3][v[0] % 3] == chr) && 
            (board[v[1] / 3][v[1] % 3] == chr) && 
            (board[v[2] / 3][v[2] % 3] == chr)) {
            return true;
        }
    }
    return false;
}

int check_possibility(int cnt_O, int cnt_X, bool win_O, bool win_X) {
    if ((!win_O && !win_X && ((cnt_O == cnt_X) || (cnt_O == cnt_X + 1))) ||
        (win_O && !win_X && (cnt_O == cnt_X + 1)) ||
        (!win_O && win_X && (cnt_O == cnt_X) )) {
        return 1;
    }
    return 0;
}

int solution(vector<string> board) {
    int cnt_O = 0;
    int cnt_X = 0;
    bool win_O = check_win(board, 'O');
    bool win_X = check_win(board, 'X');

    for (const string& str : board) {
        for (const char& chr : str) {
            if (chr == 'O') {
                cnt_O++;
            }
            else if (chr == 'X') {
                cnt_X++;
            }
        }
    }
    return check_possibility(cnt_O, cnt_X, win_O, win_X);
}

int main() {
    cout << "문제1 정답 : " << solution({ "O.X", ".O.", "..X" }) << endl;
    cout << "문제2 정답 : " << solution({ "OOO", "...", "XXX" }) << endl;
    cout << "문제3 정답 : " << solution({ "...", ".X.", "..." }) << endl;
    cout << "문제4 정답 : " << solution({ "...", "...", "..." }) << endl;
    return 0;
}