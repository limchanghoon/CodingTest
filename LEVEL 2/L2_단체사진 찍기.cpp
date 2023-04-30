#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 8;

char arr[] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

vector<string> global_data;

bool check_condition() {
    for (int i = 0; i < global_data.size(); i++) {
        int c1;
        int c2;
        char op = global_data[i][3];
        int dis = global_data[i][4] - '0';
        for (int j = 0; j < N; j++) {
            if (arr[j] == global_data[i][0])
                c1 = j;
            else if (arr[j] == global_data[i][2])
                c2 = j;
        }
        int result = abs(c1 - c2) - 1;
        if (op == '=' && result != dis)
            return false;
        else if (op == '>' && result <= dis)
            return false;
        else if (op == '<' && result >= dis)
            return false;
    }
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    global_data = data;
    std::sort(arr, arr + 8);
    do {
        if (check_condition())
            answer++;
    } while (std::next_permutation(arr, arr + 8));

    return answer;
}

int main() {
    cout << solution(2, { "N~F=0", "R~T>2" }) << endl;
    //cout << solution(2, { "M~C<2", "C~M>1" }) << endl;

    return 0;
}