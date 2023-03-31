#include <string>
#include <vector>
#include <stack>
#include <regex>
#include <algorithm>
#include <iostream>

using namespace std;

regex reg("(\\d+):(\\d+)");
smatch m1;
smatch m2;
stack<pair<string, int>> st;

bool cmp(vector<string>& a, vector<string>& b) {
    regex_match(a[1], m1, reg);
    regex_match(b[1], m2, reg);
    int h1 = stoi(m1[1]);
    int h2 = stoi(m2[1]);
    if (h1 == h2) {
        return stoi(m1[2]) < stoi(m2[2]);
    }
    else {
        return h1 < h2;
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    regex_match(plans[0][1], m1, reg);

    int start = stoi(m1[1]) * 60 + stoi(m1[2]);
    int playtime = stoi(plans[0][2]);
    string name = plans[0][0];

    for (int i = 1; i < plans.size(); i++) {
        regex_match(plans[i][1], m1, reg);
        int next = stoi(m1[1]) * 60 + stoi(m1[2]);
        while (start != next) {
            if (int dif = next - start; dif > playtime) {
                answer.push_back(name);
                if (!st.empty()) {
                    auto pr = st.top();
                    st.pop();
                    start += playtime;
                    playtime = pr.second;
                    name = pr.first;
                }
                else {
                    start = next;
                    playtime = stoi(plans[i][2]);
                    name = plans[i][0];
                }
            }
            else if (dif == playtime) {
                answer.push_back(name);
                start = next;
                playtime = stoi(plans[i][2]);
                name = plans[i][0];
            }
            else {
                st.push({ name, playtime - dif });
                start = next;
                playtime = stoi(plans[i][2]);
                name = plans[i][0];
            }
        }
    }

    // name에 마지막 시간 과제가 남음, 스택에 킵해놓은 과제도 남아 있을 수 있음
    answer.push_back(name);
    while (!st.empty()) {
        auto pr = st.top();
        st.pop();
        answer.push_back(pr.first);
    }

    return answer;
}

int main() {
    auto v = solution({ { "korean", "11:40", "30" }, {"english", "12:10", "20"}, {"math", "12:30", "40"} });
    for (auto s : v) {
        cout << s << ", ";
    }
    cout << endl;

    return 0;
}