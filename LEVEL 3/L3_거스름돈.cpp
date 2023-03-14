#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> v(n + 1);
    for (int m : money) {
        v[m]++;
        for (int i = m + 1; i < n + 1; i++) {
            v[i] += v[i - m];
        }
    }
    return v[n];
}

int main() {
    cout << "문제1 정답 : " << solution(5, { 1,2,5 }) << endl;


    return 0;
}