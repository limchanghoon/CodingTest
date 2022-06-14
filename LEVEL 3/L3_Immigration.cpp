/*

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long count = 0;
    sort(times.begin(), times.end());

    long long up = (long long)n * (long long)times.back();
    long long down = 0;
    while (true) {
        signed long long mid = (up + down) / 2;
        if (down == mid) {
            answer = up;
            break;
        }
        count = 0;
        for (int i = 0; i < times.size(); i++) {
            count += mid / times[i];
        }

        if (count >= n) {
            up = mid;
        }
        else if (count < n) {
            down = mid;
        }
    }
    return answer;
}


int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(7);
    printf("Answer : %d\n", solution(6, v));
}

*/