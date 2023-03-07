#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

int getDistance(int x, int y, int r, int c) {
    return abs(x - r) + abs(y - c);
}

// down, left, right, up을 레퍼런스로 받아서 최소한 필요한 횟수로 변경한다.
void get_dlru_count(int x, int y, int r, int c, int& down, int& left, int& right, int& up) {
    if (int vertical = r - x; vertical > 0)
        down = vertical;
    else
        up = -vertical;

    if (int horizontal = c - y; horizontal > 0)
        right = horizontal;
    else
        left = -horizontal;
    return;
}

// 사전순 d -> l -> r -> u
string solution(int n, int m, int x, int y, int r, int c, int k) {
    int down = 0, left = 0, right = 0, up = 0;
    get_dlru_count(x, y, r, c, down, left, right, up);

    if (int tmp = k - (down + left + right + up); tmp < 0 || tmp % 2 == 1)
        return "impossible";

    string answer = "";
    
    stack<pair<vector<int>,string>> s;
    s.push({ { x, y, k } ,"" });
    while (!s.empty()) {

        int cx = s.top().first[0];
        int cy = s.top().first[1];
        int remaining = s.top().first[2];
        string str = s.top().second;
        s.pop();
        if (int distance = getDistance(cx, cy, r, c);
            distance > remaining || cx < 1 || cx > n || cy < 1 || cy > m) {
            continue;
        }
        else if (remaining == 0) {
            answer = str;
            break;
        }
        else if (distance == remaining) {
            while (!s.empty()) s.pop();
        }
        remaining--;
        s.push({ {cx - 1,cy,remaining},str + "u" });
        s.push({ {cx,cy + 1,remaining},str + "r" });
        s.push({ {cx,cy - 1,remaining},str + "l" });
        s.push({ {cx + 1,cy,remaining},str + "d" });
    }

    return answer;
}

int main() {
    cout << "문제 1 정답 : " << solution(3, 4, 2, 3, 3, 1, 5) << endl;
    cout << "문제 2 정답 : " << solution(2, 2, 1, 1, 2, 2, 2) << endl;
    cout << "문제 3 정답 : " << solution(3, 3, 1, 2, 3, 3, 4) << endl;

    return 0;
}