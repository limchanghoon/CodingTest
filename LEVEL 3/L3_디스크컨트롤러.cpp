#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    bool* check = new bool[jobs.size()];
    for (int i = 0; i < jobs.size(); i++) {
        check[i] = false;
    }

    sort(jobs.begin(), jobs.end(), cmp);

    int i = 0;
    while(true) {
        int maxTime = 1001;
        int index = -1;
        for (int j = 0; j < jobs.size(); j++) {
            if (!check[j] && i >= jobs[j][0] && maxTime > jobs[j][1]) {
                maxTime = jobs[j][1];
                index = j;
            }
        }

        if (index == -1) {
            i++;
        }
        else {
            answer += i - jobs[index][0] + jobs[index][1];
            i += jobs[index][1];
            check[index] = true;
            for (int k = 0; k < jobs.size(); k++) {
                if (!check[k]) break;
                if (k == jobs.size() - 1) {
                    answer /= jobs.size();
                    return answer;
                }
            }
        }

    }
}


int main() {
    vector<vector<int>> v{ {0, 3}, {1, 9}, {2, 6} };
    printf("Result : %d\n", solution(v));
}