#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }

}

int solution(vector<vector<int>> routes) {
    if (routes.size() == 1) return 1;
    int answer = 0;

    sort(routes.begin(), routes.end(), cmp);
    int max = routes[0][1];


    for (int i = 1; i < routes.size(); i++) {
        if (i == routes.size() - 1) {
            answer++;
        }
        if (max < routes[i][0]) {
            max = routes[i][1];
            answer++;
        }
        else if (max > routes[i][1]) {
            max = routes[i][1];
        }

    }
    return answer;
}

/*
int main() {
    printf("Result : %d\n", solution({ {-20,-15}, {-14,-5}, {-18,-13}, {-5,-3 } }));
    return 0;
}
*/