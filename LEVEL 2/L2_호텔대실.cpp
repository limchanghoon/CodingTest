#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<string>& first, const vector<string>& second) {
    if (stoi(first[0].substr(0, 2)) == stoi(second[0].substr(0, 2))) {
        return stoi(first[0].substr(3, 2)) < stoi(second[0].substr(3, 2));
    }
    else {
        return stoi(first[0].substr(0, 2)) < stoi(second[0].substr(0, 2));
    }
}

int solution(vector<vector<string>> book_time) {
    vector<vector<int>> available_time;
    sort(book_time.begin(), book_time.end(),cmp);
    for (vector<string> vs : book_time) {
        int min_hour = stoi(vs[0].substr(0, 2));
        int min_minuate = stoi(vs[0].substr(3, 2));
        int min_index = -1;
        int i = 0;
        // 后规 茫扁
        for (; i < available_time.size(); i++) {
            if (min_hour > available_time[i][0] || (min_hour == available_time[i][0] && min_minuate >= available_time[i][1])) {
                min_hour = available_time[i][0];
                min_minuate = available_time[i][1];
                min_index = i;
                break;
            }
        }

        int m = stoi(vs[1].substr(3, 2)) + 10;
        int h = stoi(vs[1].substr(0, 2)) + m / 60;
        m %= 60;

        // 后规捞 绝绰 版快
        if (min_index == -1) {
            available_time.push_back({ h, m });
        }
        else {
            available_time[min_index][0] = h;
            available_time[min_index][1] = m;
        }
    }

    return available_time.size();
}

int main() {
    printf("%d\n", solution({ 
        {"15:00", "17:00"},
        {"16:40", "18:20"},
        {"14:20", "15:20"},
        {"14:10", "19:20"},
        {"18:20", "21:20"} }));
    return 0;
}