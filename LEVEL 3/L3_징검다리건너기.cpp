#include <string>
#include <vector>

using namespace std;


int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 1, end = 200000000;
    while (start < end) {
        int mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] <= mid) {
                cnt++;
            }
            else {
                cnt = 0;
            }

            if (cnt >= k) {
                end = mid;
                answer = mid;
                break;
            }

            if (i == stones.size() - 1)
                start = mid + 1;
        }
    }
    return answer;
}

/*
int main() {
    printf("Result : %d", solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3));
    return 0;
}
*/