#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int check_territory(const vector<vector<int>>& picture, vector<vector<int>>& v, int first, int second) {
    v[first][second] = 1;
    if (picture[first][second] == 0)
        return -1;

    int color = picture[first][second];
    int count = 0;
    stack<pair<int, int>> s;
    s.push({ first,second });
    while (!s.empty()) {
        int _first = s.top().first;
        int _second = s.top().second;
        s.pop();
        if (0 <= _first + 1 && _first + 1 < v.size() && v[_first + 1][_second] == 0 && picture[_first + 1][_second] == color) {
            s.push({ _first + 1,_second });
            v[_first + 1][_second] = 1;
        }
        if (0 <= _first - 1 && _first - 1 < v.size() && v[_first - 1][_second] == 0 && picture[_first - 1][_second] == color) {
            s.push({ _first - 1,_second });
            v[_first - 1][_second] = 1;
        }
        if (0 <= _second + 1 && _second + 1 < v[0].size() && v[_first][_second + 1] == 0 && picture[_first][_second + 1] == color) {
            s.push({ _first,_second + 1 });
            v[_first][_second + 1] = 1;
        }
        if (0 <= _second - 1 && _second - 1 < v[0].size() && v[_first][_second - 1] == 0 && picture[_first][_second - 1] == color) {
            s.push({ _first,_second - 1 });
            v[_first][_second - 1] = 1;
        }

        count++;
    }
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                int count = check_territory(picture, v, i, j);
                if (count != -1) {
                    number_of_area++;
                    max_size_of_one_area = max(max_size_of_one_area, count);
                }
            }
        }
    }
    

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    auto v1 = solution(6, 4, { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} });
    cout << "문제1 정답 : " << v1[0] << ", " << v1[1] << endl;

    auto v2 = solution(6, 4, { {1,1,1,0},{1,1,1,0},{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1} });
    cout << "문제2 정답 : " << v2[0] << ", " << v2[1] << endl;
    return 0;
}