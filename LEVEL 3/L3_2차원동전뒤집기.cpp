/*
#include <string>
#include <vector>

using namespace std;


void flipRow(vector<vector<int>>& v, int row) {
    for (int i = 0; i < v[0].size(); i++) {
        v[row][i] = (v[row][i] == 0) ? 1 : 0;
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 9999999;
    // 정사각형이 아니다 조심하자;;
    int RSize = beginning.size();
    int CSize = beginning[0].size();


    vector<vector<int>> v;
    // 2 ^ RSize 만큼 루프
    for (int i = 0; i < (2 << RSize); i++) {
        int count = 0;
        v.clear();
        v.assign(beginning.begin(), beginning.end());
        for (int row = 0; row < RSize; row++) {
            // row 비트가 1이면 뒤집고 0이면 안뒤집는다.
            if ((i & (2 << row)) == 0) continue;
            flipRow(v, row);
            count++;
        }

        bool Okay = true;
        for (int c = 0; c < CSize; c++) {
            // 모두 target과 같은 면이거나 모두 다른 면일 경우만
            // 목표 상태 만들기 가능! 즉 나머지 경우는 루프 탈출!
            // 또한 모두 다른 면일 때는 뒤집어야하니 count 하나 늘려야함!
            bool tf = (v[0][c] == target[0][c]) ? true : false;
            for (int r = 1; r < RSize; r++) {
                if (tf != (v[r][c] == target[r][c]) ? true : false) {
                    Okay = false;
                    break;
                }
            }
            if (!Okay) {
                break;
            }
            else {
                if (!tf)
                    count++;
            }
        }
        if (Okay)
            answer = min(count, answer);

    }
    // answer 값이 변하지 않았으면 목표 상태를 만들지 못하는 경우
    if(answer == 9999999)
        return -1;

    return answer;
}

int main() {

    printf("%d\n", solution({ {0, 1, 0, 0, 0 }, { 1, 0, 1, 0, 1 }, { 0, 1, 1, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 1, 0 } },
        { {0, 0, 0, 1, 1},{0, 0, 0, 0, 1},{0, 0, 1, 0, 1},{0, 0, 0, 1, 0},{0, 0, 0, 0, 1} }));    
    //printf("%d\n", solution({ {1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1} },
    //    { {1, 0, 1, 1},{0, 1, 1, 1},{1, 1, 1, 0},{0, 0, 1, 0} }));
    return 0;
}
*/