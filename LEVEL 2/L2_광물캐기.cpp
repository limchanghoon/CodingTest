#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int get_fatigue(int pick, string str) {
    int answer = -1;
    switch (pick)
    {
    case 0:
        answer = 1;
        break;
    case 1:
        if (str == "diamond")
            answer = 5;
        else
            answer = 1;
        break;
    case 2:
        if (str == "diamond")
            answer = 25;
        else if (str == "iron")
            answer = 5;
        else
            answer = 1;
        break;
    default:
        break;
    }
    return answer;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = INT_MAX;
    // 0~2 picks 3 : ÀÎµ¦½º, 4 : ÇÇ·Îµµ
    queue<vector<int>> q;
    q.push({ picks[0], picks[1], picks[2], 0, 0 });
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        // °¢ °î±ªÀÌ¸¦ ¾²´Â °æ¿ì
        for (int pick = 0; pick < 3; pick++) {
            if (v[pick] > 0) {
                int i = 0;
                int x = 0;
                for (; i < 5; i++) {
                    x += get_fatigue(pick, minerals[v[3] + i]);
                    if (v[3] + i == minerals.size() - 1) {
                        break;
                    }
                }
                if (i == 5) {
                    switch (pick) {
                    case 0:
                        q.push({ v[0] - 1, v[1], v[2], v[3] + i, v[4] + x });
                        break;
                    case 1:
                        q.push({ v[0], v[1] - 1, v[2], v[3] + i, v[4] + x });
                        break;
                    case 2:
                        q.push({ v[0], v[1], v[2] - 1, v[3] + i, v[4] + x });
                        break;
                    default:
                        break;
                    }
                }
                else
                    answer = min(answer, v[4] + x);
            }
        }

        // °î±ªÀÌ ¾ø´Â °æ¿ì
        if (v[0] == 0 && v[1] == 0 && v[2] == 0) {
            answer = min(answer, v[4]);
        }

    }
    return answer;
}

int main() {
    cout << solution({ 1,2,3 }, 
        { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" }) 
        << endl;
    cout << solution({ 0,1,1 }, 
        { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" }) 
        << endl;

    return 0;
}