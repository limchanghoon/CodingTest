#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int quotient = n;
    int remainder = n;
    while (quotient > 0) {
        remainder = quotient % 3;
        quotient /= 3;
        switch (remainder)
        {
        case 0:
            quotient--;
            answer += "4";
            break;
        case 1:
            answer += "1";
            break;
        case 2:
            answer += "2";
            break;
        default:
            return "Error in switch";
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    cout << "1 => " << solution(1) << endl;
    cout << "2 => " << solution(2) << endl;
    cout << "3 => " << solution(3) << endl;
    cout << "4 => " << solution(4) << endl;
    cout << "12 => " << solution(12) << endl;
    cout << "13 => " << solution(13) << endl;
    cout << "30 => " << solution(30) << endl;
    return 0;
}