#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    // �ε��� i�� i + 1 ��° ����
    // �ε��� 0�� 1��° ����
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
    cout << "���� 1 ���� : " << solution(8, 4, { 2,3,6 }) << endl;
    cout << "���� 2 ���� : " << solution(5, 4, { 1,3 }) << endl;
    cout << "���� 3 ���� : " << solution(4, 1, { 1,2,3,4 }) << endl;
    return 0;
}