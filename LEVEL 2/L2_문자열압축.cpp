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
    cout <<"����1 ���� : " << solution("aabbaccc") << endl;
    cout <<"����2 ���� : " << solution("ababcdcdababcdcd") << endl;
    cout <<"����3 ���� : " << solution("abcabcdede") << endl;
    cout <<"����4 ���� : " << solution("abcabcabcabcdededededede") << endl;
    cout <<"����5 ���� : " << solution("xababcdcdababcdcd") << endl;
}