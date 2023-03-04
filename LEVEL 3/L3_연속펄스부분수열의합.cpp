#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long max_LL(long long a, long long b) {
    return a > b ? a : b;
}

long long solution(vector<int> sequence) {
    vector<long long> plus_minus;
    vector<long long> minus_plus;
    plus_minus.push_back(sequence[0]);
    minus_plus.push_back(-sequence[0]);
    for (size_t i = 1; i < sequence.size(); i++) {
        if (i % 2 == 0) {
            plus_minus.push_back(max_LL(plus_minus[i-1] + sequence[i], sequence[i]));
            minus_plus.push_back(max_LL(minus_plus[i-1] - sequence[i], -sequence[i]));
        }
        else {
            plus_minus.push_back(max_LL(plus_minus[i - 1] - sequence[i], -sequence[i]));
            minus_plus.push_back(max_LL(minus_plus[i - 1] + sequence[i], sequence[i]));
        }
    }

    long long answer = max_LL(*max_element(plus_minus.begin(), plus_minus.end()), *max_element(minus_plus.begin(), minus_plus.end()));
    return answer;
}

int main() {
    cout << "Á¤´ä : " << solution({ 2, 3, -6, 1, 3, -1, 2, 4 }) << endl;
    return 0;
}
