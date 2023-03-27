#include<vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> trace(100, vector<int>(100));

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = -1;
    queue<vector<int>> q;
    // 첫번째는 answer값 저장용
    // 두번째 세번째는 현재 좌표
    q.push({ {1,0,0} });
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        int cnt = v[0];
        int x = v[1];
        int y = v[2];

        if (x == n-1 && y == m - 1) {
            answer = cnt;
            break;
        }

        if (x + 1 >= 0 && x + 1 < n && y >= 0 && y < m && maps[x + 1][y] == 1 && trace[x + 1][y] == 0) {
            trace[x + 1][y] = 1;
            q.push({ cnt + 1,x + 1,y });
        }
        if (x - 1 >= 0 && x - 1 < n && y >= 0 && y < m && maps[x - 1][y] == 1 && trace[x - 1][y] == 0) {
            trace[x - 1][y] = 1;
            q.push({ cnt + 1,x - 1,y });
        }
        if (x >= 0 && x < n && y + 1 >= 0 && y + 1 < m && maps[x][y + 1] == 1 && trace[x][y + 1] == 0) {
            trace[x][y + 1] = 1;
            q.push({ cnt + 1,x,y + 1 });
        }
        if (x >= 0 && x < n && y - 1 >= 0 && y - 1 < m && maps[x][y - 1] == 1 && trace[x][y - 1] == 0) {
            trace[x][y - 1] = 1;
            q.push({ cnt + 1,x,y - 1 });
        }
    }
    return answer;
}

int main() {
    cout << solution({ {1,0,1,1,1} ,{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} }) << endl;
    cout << solution({ {1,0,1,1,1} ,{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1} }) << endl;
}