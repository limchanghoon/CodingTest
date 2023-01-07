#include <vector>
#include <algorithm>

using namespace std;

// 이중 벡터의 인덱스 0을 기준으로 오름차순 정렬을 한다. 인덱스 0이 같을 경우 인덱스 1을 기준으로 오름차순 정렬을 한다.
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end(), cmp);
    for (int i = 0; i < n; i++) {
        // 좌표 하나씩 검사한다.

        // 밑의 for문을 돌면서 체크하고 있는 X좌표
        int curX = data[i][0];
        
        // 좌우 좌표 최대값으로 초기화, 해당 변수로 가능한 좌표를 체크함.
        int right = 2147483647;
        int left = 0;

        // 밑의 for문에서 체크하는 X좌표가 증가하면 preRight와 preLeft로 right와 left를 임시 저장함.
        int preRight = 2147483647;
        int preLeft = 0;

        // 현재 좌표(가시성을 위해)
        int startX = data[i][0];
        int startY = data[i][1];


        for (int j = i; j < n; j++) {
            if (curX < data[j][0]) {
                preRight = right;
                preLeft = left;
                curX = data[j][0];
            }

            if (startX != data[j][0] && startY != data[j][1]) {
                if (preLeft <= data[j][1] && data[j][1] < startY) {
                    answer++;
                    if (left < data[j][1]) {
                        left = data[j][1];
                    }
                }
                if (data[j][1] <= preRight && startY < data[j][1]) {
                    answer++;
                    if (data[j][1] < right) {
                        right = data[j][1];
                    }
                }
            }

        }
    }

    return answer;
}

/*
int main() {
    //vector<vector<int>> v = { {0, 0}, {1, 1}, {0, 2}, {2, 0} };
    vector<vector<int>> v = { {0, 0}, {0, 2}, {1, 1}, {1, 3},{1, 4}, {2, 0}, {2, 2}, {3, 2}, {4, 3} };
    printf("result : %d\n", solution(v.size(), v));
    return 0;
}

*/