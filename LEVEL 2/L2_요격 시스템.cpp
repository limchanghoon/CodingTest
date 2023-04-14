#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), cmp);
    int current = targets[0][1];
    for (int i = 0; i < targets.size(); i++) {
        if (current <= targets[i][0]) {
            answer++;
            current = targets[i][1];
        }
        else if(current > targets[i][1]) {
            current = targets[i][1];
        }
    }


    return answer;
}

int main() {
    cout << solution({ {4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4} }) << endl;

    return 0;
}