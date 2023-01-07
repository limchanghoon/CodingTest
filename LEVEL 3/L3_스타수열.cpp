#include <string>
#include <vector>
#include <set>

using namespace std;

int cnt_in_vector[500001];


int solution(vector<int> a) {
    int answer = 0;

    // 중복 없는 집합을 사용함
    set<int> nums;
    for (int i : a) {
        cnt_in_vector[i]++;
        nums.insert(i);
    }

    for (int N : nums) {
        // 벡터에 있는 N의 갯수*2가 최대 가능한 갯수다.
        // 지금까지 구한 answer가 이것보다 크다면 계산할 필요 없다.
        
            // 여기 부분이 시간초과를 극복하는 중요한 부분인데
            // 그나마 열심히 구상했지만
            // 테스트 시간을 보면 살짝 애매한 느낌이 있다...
        
        if (cnt_in_vector[N] * 2 <= answer)
            continue;
        int count = 0;
        bool req_other = true;
        bool req_N = true;
        // N이 한번 나오고 N이 아닌 것이 한번 나오면 
        // (머가 먼저 나오나는 상관없음)
        // 수열이 2씩 커진다.
        for (int i = 0; i < a.size(); i++) {
            if (req_N && a[i] == N) {
                req_N = false;
            }
            else if (req_other && a[i] != N) {
                req_other = false;
            }
            if (!req_N && !req_other) {
                req_N = true;
                req_other = true;
                count += 2;
            }
        }
        answer = max(answer, count);
    }
    return answer;
}

/*
int main() {
    printf("%d\n", solution({ 0 }));
    printf("%d\n", solution({ 5,2,3,3,5,3 }));
    printf("%d\n", solution({ 0,3,3,0,7,2,0,2,2,0 }));
    return 0;
}
*/