#include <string>
#include <vector>
#include <set>

using namespace std;

int cnt_in_vector[500001];


int solution(vector<int> a) {
    int answer = 0;

    // �ߺ� ���� ������ �����
    set<int> nums;
    for (int i : a) {
        cnt_in_vector[i]++;
        nums.insert(i);
    }

    for (int N : nums) {
        // ���Ϳ� �ִ� N�� ����*2�� �ִ� ������ ������.
        // ���ݱ��� ���� answer�� �̰ͺ��� ũ�ٸ� ����� �ʿ� ����.
        
            // ���� �κ��� �ð��ʰ��� �غ��ϴ� �߿��� �κ��ε�
            // �׳��� ������ ����������
            // �׽�Ʈ �ð��� ���� ��¦ �ָ��� ������ �ִ�...
        
        if (cnt_in_vector[N] * 2 <= answer)
            continue;
        int count = 0;
        bool req_other = true;
        bool req_N = true;
        // N�� �ѹ� ������ N�� �ƴ� ���� �ѹ� ������ 
        // (�Ӱ� ���� �������� �������)
        // ������ 2�� Ŀ����.
        for (int i = 0; i < a.size(); i++) {
            if (req_N && a[i] == N) {
                req_N = false;
            }
            else if (req_other && a[i] != N) {
                req_other = false;
            }
            if (!req_N && !req_other) {
                req_N = true;
                req_other = true;
                count += 2;
            }
        }
        answer = max(answer, count);
    }
    return answer;
}

/*
int main() {
    printf("%d\n", solution({ 0 }));
    printf("%d\n", solution({ 5,2,3,3,5,3 }));
    printf("%d\n", solution({ 0,3,3,0,7,2,0,2,2,0 }));
    return 0;
}
*/