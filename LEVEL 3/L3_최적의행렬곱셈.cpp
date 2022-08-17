/*
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    vector<vector<int>> v(matrix_sizes.size(), vector<int>(matrix_sizes.size()));
    for (int i = 0; i < matrix_sizes.size() - 1; i++) {
        v[i][i + 1] = matrix_sizes[i][0] * matrix_sizes[i][1] * matrix_sizes[i + 1][1];
    }
    // j ~ j+2 (3개)의 최적의 곱 구하기 => A(BC), (AB)C
    // j ~ j+3 (4개)의 최적의 곱 구하기 => A(BCD), (AB)(CD), (ABC)D
    // j ~ j+4 (5개)의 최적의 곱 구하기 => A(BCDE), (AB)(CDE), (ABC)(DE), (ABCD)E
    // ...
    // j ~ j+행렬 갯수-1 (행렬 갯수)의 최적의 곱 구하기
    for (int i = 2; i < matrix_sizes.size(); i++) {
        for (int j = 0; j < matrix_sizes.size() - i; j++) {
            int min = 24000001;

            for (int k = j; k < j + i; k++) {
                if (min > v[j][k] + v[k + 1][j + i] + matrix_sizes[j][0] * matrix_sizes[k][1] * matrix_sizes[j + i][1]) {
                    min = v[j][k] + v[k + 1][j + i] + matrix_sizes[j][0] * matrix_sizes[k][1] * matrix_sizes[j + i][1];
                }
            }

            v[j][j + i] = min;
        }
    }
    answer = v[0][matrix_sizes.size() - 1];
    return answer;
}

int main() {

    printf("result : %d\n", solution({ {5,3},{3,10},{10,6} }));
    return 0;
}
*/