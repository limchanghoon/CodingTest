#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (size_t i = 1; i <= s.size(); i++) {
        int total = 0;
        size_t j = 0;
        for (; j < s.size(); j+=i) {
            int count = 1;
            while (true) {
                if (j + i + i - 1 < s.size() && s.substr(j, i) == s.substr(j + i, i)) {
                    count++;
                    j += i;
                }
                else 
                    break;
            }
            total += i;
            if (count != 1)
                total += to_string(count).size();
        }
        total -= j - s.size();
        answer = min(answer, total);
    }
    return answer;
}

int main() {
    cout <<"문제1 정답 : " << solution("aabbaccc") << endl;
    cout <<"문제2 정답 : " << solution("ababcdcdababcdcd") << endl;
    cout <<"문제3 정답 : " << solution("abcabcdede") << endl;
    cout <<"문제4 정답 : " << solution("abcabcabcabcdededededede") << endl;
    cout <<"문제5 정답 : " << solution("xababcdcdababcdcd") << endl;
}