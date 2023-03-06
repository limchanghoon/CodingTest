#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<string> maps) {
    size_t width = maps[0].size();
    size_t height = maps.size();
    vector<vector<int>> start_to_lever(height, vector<int>(width, 99999));
    vector<vector<int>> lever_to_end(height, vector<int>(width, 99999));
    queue<vector<int>> q;

    pair<int, int> start;
    pair<int, int> lever;
    pair<int, int> end;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            switch (maps[i][j])
            {
            case 'S':
                start.first = i;
                start.second = j;
                break;
            case 'L':
                lever.first = i;
                lever.second = j;
                break;
            case 'E':
                end.first = i;
                end.second = j;
                break;
            default:
                break;
            }
        }
    }

    // start에서 lever까지
    q.push({ start.first, start.second, 0 });
    while (!q.empty()) {
        int row = q.front()[0];
        int col = q.front()[1];
        int score = q.front()[2];
        q.pop();
        if (row < 0 || row >= maps.size() || col < 0 || col >= maps[0].size()
            || maps[row][col] == 'X' || start_to_lever[row][col] <= score || start_to_lever[lever.first][lever.second] <= score) {
            continue;
        }
        start_to_lever[row][col] = score;
        if (row != lever.first || col != lever.second) {
            q.push({ row + 1, col, score + 1 });
            q.push({ row - 1, col, score + 1 });
            q.push({ row, col + 1, score + 1 });
            q.push({ row, col - 1, score + 1 });
        }
    }
    if (start_to_lever[lever.first][lever.second] == 99999)
        return -1;

    // lever에서 end까지
    q.push({ lever.first, lever.second, 0 });
    while (!q.empty()) {
        int row = q.front()[0];
        int col = q.front()[1];
        int score = q.front()[2];
        q.pop();
        if (row < 0 || row >= maps.size() || col < 0 || col >= maps[0].size()
            || maps[row][col] == 'X' || lever_to_end[row][col] <= score || lever_to_end[end.first][end.second] <= score) {
            continue;
        }
        lever_to_end[row][col] = score;
        if (row != end.first || col != end.second) {
            q.push({ row + 1, col, score + 1 });
            q.push({ row - 1, col, score + 1 });
            q.push({ row, col + 1, score + 1 });
            q.push({ row, col - 1, score + 1 });
        }
    }
    if (lever_to_end[end.first][end.second] == 99999)
        return -1;

    return start_to_lever[lever.first][lever.second] + lever_to_end[end.first][end.second];
}

int main() {
    cout << "문제 1 정답 : " << solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" }) << endl;
    cout << "문제 2 정답 : " << solution({ "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" }) << endl;

    return 0;
}