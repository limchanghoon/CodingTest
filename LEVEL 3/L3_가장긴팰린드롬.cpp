#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        if (answer > s.size() - i)   break;
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                int mid = (i + j) / 2;
                int tJ = j - 1;
                bool check = true;
                for (int k = i + 1; k <= mid; k++) {
                    if (s[k] != s[tJ]) {
                        check = false;
                        break;
                    }
                    tJ--;
                }
                if (check && answer < j - i + 1) {
                    answer = j - i + 1;
                }
            }
        }
    }

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << answer << endl;

    return answer;
}

int main() {
    solution("abacde");
}