#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> v(e + 1, 1);
    vector<int> max_v(e + 1);

    // ���Ⱑ �ٽ� ��ü ��� ���ϴ� �˰���(�˻����� ã��..)
    for (int i = 2; i <= e; i++) {
        for (int k = 1; k <= e / i; k++) {
            v[i * k]++;
        }
    }

    int max_num = 0;
    int max_index = 0;
    for (int i = e; i >= 1; i--) {
        if (max_num <= v[i]) {
            max_num = v[i];
            max_index = i;
        }
        max_v[i] = max_index;
    }

    for (int start : starts) {
        answer.push_back(max_v[start]);
    }
    return answer;
}

int main() {
    vector<int> v = solution(8, {1,3,7});
    printf("%d, %d ,%d\n",v[0],v[1],v[2]);
    return 0;
}