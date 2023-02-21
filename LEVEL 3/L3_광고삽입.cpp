#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

string timeToStr(int time) {
    string answer = "";
    int hour = time / 3600;
    if (hour < 10)
        answer += "0";
    answer += to_string(hour) + ":";

    int minute = time % 3600 / 60;
    if (minute < 10)
        answer += "0";
    answer += to_string(minute) + ":";

    int second = time % 60;
    if (second < 10)
        answer += "0";
    answer += to_string(second);
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    // string을 int로 변환 (초('s)로 변환)
    regex reg("([0-9][0-9]):([0-5][0-9]):([0-5][0-9])-([0-9][0-9]):([0-5][0-9]):([0-5][0-9])");
    regex reg2("([0-9][0-9]):([0-5][0-9]):([0-5][0-9])");
    smatch m;
    regex_match(play_time, m, reg2);
    int play_time_s = 60 * 60 * stoi(m[1]) + 60 * stoi(m[2]) + stoi(m[3]);
    regex_match(adv_time, m, reg2);
    int adv_time_s = 60 * 60 * stoi(m[1]) + 60 * stoi(m[2]) + stoi(m[3]);

    // 100시간 * 60 * 60
    vector<int> results(360000);
    for (const string& str : logs) {
        regex_match(str, m, reg);
        int start = 60 * 60 * stoi(m[1]) + 60 * stoi(m[2]) + stoi(m[3]);
        int end = 60 * 60 * stoi(m[4]) + 60 * stoi(m[5]) + stoi(m[6]);

        for (size_t i = start; i < end; i++) {
            results[i]++;
        }
    }

    long long value = 0;
    long long maxValue = 0;
    long long maxTime = 0;
    for (int i = 0; i < adv_time_s; i++) {
        value += results[i];
    }
    maxValue = value;

    // 투 포인터 사용 p1 빼고, p2 더한다.
    for (int p1 = 0, p2 = adv_time_s; p2 < play_time_s; p1++, p2++) {
        value -= results[p1];
        value += results[p2];
        if (maxValue < value) {
            maxValue = value;
            maxTime = p1 + 1;
        }
    }

    string answer = timeToStr(maxTime);

    return answer;
}

int main() {
    cout << "정답 : " << solution("02:03:55", "00:14:15", 
        { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" }) 
        << endl;
    return 0;
}