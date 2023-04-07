#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(sequence.size()-1);
    int p1 = 0, p2 = 0;
    int sum = sequence[0];
    while (p2 < sequence.size()) {
        if (sum == k) {
            if (p2 - p1 < answer[1] - answer[0]) {
                answer[0] = p1;
                answer[1] = p2;
            }
        }

        if (sum >= k) {
            sum -= sequence[p1++];
            if (p1 > p2)
                p2 = p1;
        }
        else {
            ++p2;
            if(p2 < sequence.size()){
                if (sequence[p2] > k) {
                    p2++;
                    p1 = p2;
                }
                else {
                    sum += sequence[p2];
                }
            }
        }
    }
    return answer;
}

int main() {
    auto v = solution({ 1, 2, 3, 4, 5 }, 7);

    cout << v[0] << ", " << v[1] << endl;

    return 0;
}