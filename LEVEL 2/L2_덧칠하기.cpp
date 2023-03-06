#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    // 인덱스 i가 i + 1 번째 구역
    // 인덱스 0은 1번째 구역
    int clear = section[0] + m - 1;
    for (int i = 1; i < section.size(); i++) {
        if (section[i] > clear) {
            answer++;
            clear = section[i] + m - 1;
        }
    }
    return answer;
}

int main() {
    cout << "문제 1 정답 : " << solution(8, 4, { 2,3,6 }) << endl;
    cout << "문제 2 정답 : " << solution(5, 4, { 1,3 }) << endl;
    cout << "문제 3 정답 : " << solution(4, 1, { 1,2,3,4 }) << endl;
    return 0;
}