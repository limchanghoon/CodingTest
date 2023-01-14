#include <string>
#include <vector>
#include <queue>

using namespace std;

// 너비우선 탐색
int solution(string begin, string target, vector<string> words) {
    queue<string> q1;
    queue<vector<string>> q2;
    queue<int> q3;
    q1.push(begin);
    q2.push(words);
    q3.push(0);
    while (!q1.empty()) {
        string curStr = q1.front();
        vector<string> curWords = q2.front();
        int cnt = q3.front();

        q1.pop();
        q2.pop();
        q3.pop();

        int count = 0;
        for (int i = 0; i < curWords.size(); i++) {
            count = 0;
            for (int j = 0; j < begin.size(); j++) {
                if (curStr[j] != curWords[i][j]) {
                    if (++count > 1)
                        break;
                }
            }
            if (count == 1) {
                if (curWords[i].compare(target) == 0)
                    return cnt + 1;
                q1.push(curWords[i]);
                vector<string> v = curWords;
                v.erase(v.begin() + i);
                q2.push(v);
                q3.push(cnt + 1);
            }
        }
    }

    return 0;
}

int main() {
    printf("%d\n", solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }));
    printf("%d\n", solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }));
    return 0;
}