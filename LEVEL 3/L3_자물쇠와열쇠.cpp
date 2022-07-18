#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();
    vector<vector<int>> NNK(N, vector<int>(N));

    for (int loop = 0; loop < 4; loop++) {
        // 90도 회전
        vector<vector<int>> rotatekey(M, vector<int>(M));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                rotatekey[j][M - i - 1] = key[i][j];
            }
        }
        key = rotatekey;
        
        // lock의 모든 칸을 검사
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                // lock의 모든 칸에 key의 모든 모양을 맞춰본다.
                for (int k = 0; k < M; k++) {
                    for (int r = 0; r < M; r++) {
                        NNK.assign(N, vector<int>(N));
                        for (int x = 0; x + k < M && i + x < N; x++) {
                            for (int y = 0; y + r < M && j + y < N; y++) {
                                NNK[i + x][j + y] = key[x + k][y + r];
                            }
                        }

                        // (N*N으로 확장시킨)key와 lock의 합이 모든칸에서 1이면 check는 true
                        bool check = true;
                        for (int x = 0; x < N; x++) {
                            for (int y = 0; y < N; y++) {
                                if (NNK[x][y] + lock[x][y] != 1)
                                {
                                    check = false;
                                    break;
                                }
                            }
                            if (!check)  break;
                        }
                        if (check)   return true;

                    }
                }

            }
        }
        
    }
    bool answer = false;
    return answer;
}

int main() {

    vector<vector<int>> k = { { 0, 0, 0 } , {1, 0, 0} ,{0, 1, 1} };
    vector<vector<int>> l = { { 1, 1, 1 } , {1, 1, 0} ,{1, 0, 1} };

    if (solution(k, l)) {
        printf("Result = True \n");
    }
    else {
        printf("Result = False \n");
    }

    return 0;
}