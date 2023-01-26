#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ù��° ���ҷ� �������� ����
// ù��° ���Ұ� ������ �ι�° ���ҷ� ��������
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> scores) {
    // ��ȣ �ڽ� or ��ȣ�� ���� ��� or ��ȣ���� ���� ����� �� answer--  
    int answer = scores.size() + 1;
    int s1 = scores[0][0];
    int s2 = scores[0][1];
    int sum = s1 + s2;
    sort(scores.begin(),scores.end(), cmp);
    for (size_t i = 0; i < scores.size(); i++) {
        // ��ȣ �μ�Ƽ�� �� �޴� ���
        if (s1 < scores[i][0] && s2 < scores[i][1]) {
            return -1;
        }
        // i�� �ش��ϴ� ����� ��ȣ�� ���� ���(Ȥ�� ��ȣ �ڽ�)�̰ų� ���� ���
        if (scores[i][0] + scores[i][1] <= sum) {
            answer--;
            continue;
        }
        // �������� �����߱� ������ i�� �ڿ� �ִ� ����� i�� ���ؼ� i�� �Ǵ��Ѵ�.
        for (size_t k = i+1; k < scores.size(); k++) {
            if ((scores[i][0] < scores[k][0] && scores[i][1] < scores[k][1])) {
                answer--;
                break;
            }
        }
    }
    return answer;
}

int main() {
    printf("%d\n", solution({ {2,2},{1,4},{3,2},{3,2},{2,1} }));
    return 0;
}