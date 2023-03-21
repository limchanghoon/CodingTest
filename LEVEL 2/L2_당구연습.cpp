#include <string>
#include <vector>
#include <limits.h>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (vector<int> v : balls) {
        int result = INT_MAX;
        // ╩С
        if (startX != v[0] || startY > v[1]) {
            int delX = abs(startX - v[0]);
            int delY = 2 * n - startY - v[1];
            result = min(result, delX * delX + delY * delY);
        }

        // го
        if (startX != v[0] || startY < v[1]) {
            int delX = abs(startX - v[0]);
            int delY = startY + v[1];
            result = min(result, delX * delX + delY * delY);
        }

        //аб
        if (startY != v[1] || startX < v[0]) {
            int delX = startX + v[0];
            int delY = abs(startY - v[1]);
            result = min(result, delX * delX + delY * delY);
        }

        //©Л
        if (startY != v[1] || startX > v[0]) {
            int delX = 2 * m - startX - v[0];
            int delY = abs(startY - v[1]);
            result = min(result, delX * delX + delY * delY);
        }
        answer.push_back(result);
    }
    return answer;
}

int main() {
    vector<int> v = solution(10, 10, 3, 7, { {7,7},{2,7},{7,3} });
    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}