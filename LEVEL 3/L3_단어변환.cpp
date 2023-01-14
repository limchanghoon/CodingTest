#include <string>
#include <vector>
#include <queue>

using namespace std;

class W {
public:
    W(string _begin, vector<string> _words) {
        begin = _begin;
        words.assign(_words.begin(), _words.end());
        cnt = 0;
    }

    W(string _begin, vector<string> _words, int erase, int _cnt) {
        begin = _begin;
        _words.erase(_words.begin() + erase);
        words = _words;
        cnt = _cnt;
    }

    string begin;
    vector<string> words;
    int cnt;
};

// 너비 우선 탐색
int solution(string begin, string target, vector<string> words) {
    queue<W> q;

    q.push(W(begin, words));

    while (!q.empty()) {
        W w = q.front();
        q.pop();
        int count = 0;
        for (int i = 0; i < w.words.size(); i++) {
            count = 0;
            for (int j = 0; j < begin.size(); j++) {
                if (w.begin[j] != w.words[i][j]) {
                    if (++count > 1)
                        break;
                }
            }
            if (count == 1) {
                if (w.words[i].compare(target) == 0)
                    return w.cnt + 1;
                q.push(W(w.words[i], w.words, i, w.cnt + 1));
            }
        }
    }
    return 0;
}

int main() {
    printf("%d\n",solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}));
    printf("%d\n", solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }));
    return 0;
}