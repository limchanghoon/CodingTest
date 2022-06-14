#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> sv = triangle;
    sv[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if(sv[i + 1][j] < sv[i][j] + triangle[i + 1][j])
                sv[i + 1][j] = sv[i][j] + triangle[i + 1][j];
            if(sv[i + 1][j + 1] < sv[i][j] + triangle[i + 1][j + 1])
                sv[i + 1][j + 1] = sv[i][j] + triangle[i + 1][j + 1];
        }
    }

    for (int i = 0; i < sv.back().size(); i++) {
        if (answer < sv.back()[i])
            answer = sv.back()[i];
    }
    return answer;
}



int main() {

    vector<vector<int>> v = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };

    printf("Result : %d\n", solution(v));
    return 0;
}