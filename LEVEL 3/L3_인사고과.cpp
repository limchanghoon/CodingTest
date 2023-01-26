#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 첫번째 원소로 오름차순 정렬
// 첫번째 원소가 같으면 두번째 원소로 오름차순
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> scores) {
    // 원호 자신 or 원호와 같은 등수 or 원호보다 낮은 등수일 때 answer--  
    int answer = scores.size() + 1;
    int s1 = scores[0][0];
    int s2 = scores[0][1];
    int sum = s1 + s2;
    sort(scores.begin(),scores.end(), cmp);
    for (size_t i = 0; i < scores.size(); i++) {
        // 원호 인센티브 못 받는 경우
        if (s1 < scores[i][0] && s2 < scores[i][1]) {
            return -1;
        }
        // i에 해당하는 사람이 원호와 같은 등수(혹은 원호 자신)이거나 낮은 등수
        if (scores[i][0] + scores[i][1] <= sum) {
            answer--;
            continue;
        }
        // 오름차순 정렬했기 때문에 i에 뒤에 있는 사람만 i랑 비교해서 i를 판단한다.
        for (size_t k = i+1; k < scores.size(); k++) {
            if ((scores[i][0] < scores[k][0] && scores[i][1] < scores[k][1])) {
                answer--;
                break;
            }
        }
    }
    return answer;
}

int main() {
    printf("%d\n", solution({ {2,2},{1,4},{3,2},{3,2},{2,1} }));
    return 0;
}