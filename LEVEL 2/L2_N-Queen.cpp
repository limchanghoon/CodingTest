#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
int answer = 0;

bool check(int stage) {
    for (int i = 0; i < stage; i++) {
        if (v[i] == v[stage] || abs(i - stage) == abs(v[i] - v[stage]))
            return false;
    }
    return true;
}

void backTracking(int stage) {
    if (stage == v.size()) {
        answer++;
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        v[stage] = i;
        if (check(stage)) {
            backTracking(stage + 1);
        }
    }
}

int solution(int n) {
    v.resize(n);
    answer = 0;
    backTracking(0);
    return answer;
}

int main() {
    cout << solution(1) << endl;
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;
    cout << solution(5) << endl;

    return 0;
}