#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
// 첫번째 풀이
struct PR {
    int num, index;
    PR(int _num, int _index) : num(_num), index(_index) {}
};

struct CMP {
    bool operator()(PR a, PR b) {
        return a.num > b.num;
    }
};

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    priority_queue<PR, vector<PR>, CMP> q;
    for (size_t i = 0; i < numbers.size(); i++) {
        while (!q.empty()) {
            if (q.top().num >= numbers[i]) {
                break;
            }
            else {
                answer[q.top().index] = numbers[i];
                q.pop();
            }
        }
        q.push(PR(numbers[i], i));
    }
    return answer;
}
*/

// 좀더 효율적인 풀이
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> s;   // 요소가 인덱스
    for (size_t i = 0; i < numbers.size(); i++) {
        while (!s.empty()) {
            if (numbers[s.top()] < numbers[i]) {
                answer[s.top()] = numbers[i];
                s.pop();
            }
            else {
                break;
            }
        }
        s.push(i);
    }
    return answer;
}

int main() {
    //auto v = solution({2,3,3,5});
    auto v = solution({9,1,5,3,6,2});
    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}