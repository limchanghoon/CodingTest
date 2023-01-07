/*
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int* parents = new int[n];
    vector<vector<int>> networks(n);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        networks[i].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (computers[i][j] == 1) {
                // ���� ��Ʈ��ũ�� �ƴϸ�
                // (j�� �θ�)�� �θ�� �ϴ� ��Ʈ��ũ�� 
                // ���� i�� �θ�� �ϴ� ��Ʈ��ũ�� �ٲ۴�.
                if (parents[i] != parents[j]) {
                    int tmp = parents[j];
                    for (int node : networks[parents[j]]) {
                        parents[node] = parents[i];
                        networks[parents[i]].push_back(node);
                    }
                    networks[tmp].clear();
                }
            }

        }
    }

    for (int i = 0; i < n; i++) {
        if (!networks[i].empty())
            answer++;
    }

    return answer;
}

int main() {
    printf("%d\n", solution(3, { {1,0,1}, {0,1,0,}, {1,0,1} }));
    printf("%d\n", solution(5, { {1,1,0,0,0}, {1,1,0,1,0}
    , {0,0,1,0,1}, {0,1,0,1,1}, {0,0,1,1,1} }));

    return 0;
}
*/