#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq1;    // 내림차순
    priority_queue<int, vector<int>, greater<int>> pq2;    // 오름차순
    int count = 0;
    for (int i = 0; i < operations.size(); i++) {
        switch (operations[i][0]) {
            case 'I':
                count++;
                if (operations[i][2] == '-') {
                    pq1.push(-stoi(operations[i].substr(3, operations[i].length() - 3)));
                    pq2.push(-stoi(operations[i].substr(3, operations[i].length() - 3)));
                }
                else {
                    pq1.push(stoi(operations[i].substr(2, operations[i].length() - 2)));
                    pq2.push(stoi(operations[i].substr(2, operations[i].length() - 2)));
                }
                break;
            case 'D':
                count--;
                if (operations[i][2] == '1') {
                    if (!pq1.empty()) {
                        pq1.pop();
                    }
                }
                else {
                    if (!pq2.empty()) {
                        pq2.pop();
                    }
                }

                if (count <= 0) {
                    count = 0;
                    while (!pq1.empty()) {
                        pq1.pop();
                    }
                    while (!pq2.empty()) {
                        pq2.pop();
                    }
                }

            default:
                break;
        }
    }
    if (pq1.empty() || pq2.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
    return answer;
}

/*
int main() {

    //vector<string> v = { {"I 7"}, {"I 5"}, {"I -5"}, {"D -1"} };

    vector<string> v = { {"I 16"}, {"I -5643"}, {"D -1"}, {"D 1"}, {"D 1"}, {"I 123"}, {"D -1"} };
    vector<int> result = solution(v);
    printf("Result : [%d, %d]\n", result[0], result[1]);

    return 0;
}

*/