#include <string>
#include <vector>
#include <queue>

using namespace std;



// 그냥 풀이
int solution1(vector<vector<int>> jobs) {
    int answer = 0;
    bool* check = new bool[jobs.size()];
    for (int i = 0; i < jobs.size(); i++) {
        check[i] = false;
    }

    int i = 0;
    while(true) {
        int minTime = 1001;
        int index = -1;
        for (int j = 0; j < jobs.size(); j++) {
            if (!check[j] && i >= jobs[j][0] && minTime > jobs[j][1]) {
                minTime = jobs[j][1];
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



// 우선순위 큐 사용한 풀이
struct compare
{
    bool operator() (const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    }
};

int solution2(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>,compare> pq;

    bool* check = new bool[jobs.size()];
    for (int i = 0; i < jobs.size(); i++) {
        check[i] = false;
    }

    int i = 0;
    while (true) {
        for (int j = 0; j < jobs.size(); j++) {
            if (!check[j] && i >= jobs[j][0]) {
                pq.push(jobs[j]);
                check[j] = true;
            }
        }

        if (pq.empty()) {
            i++;
        }
        else {
            answer += i - pq.top()[0] + pq.top()[1];
            i += pq.top()[1];
            pq.pop();

            if (pq.empty()) {
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
}

/*
int main() {
    vector<vector<int>> v{ {0, 3}, {1, 9}, {2, 6} };
    printf("Result : %d\n", solution(v));
}
*/