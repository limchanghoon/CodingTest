/*
#include <string>
#include <vector>

using namespace std;


void flipRow(vector<vector<int>>& v, int row) {
    for (int i = 0; i < v[0].size(); i++) {
        v[row][i] = (v[row][i] == 0) ? 1 : 0;
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 9999999;
    // ���簢���� �ƴϴ� ��������;;
    int RSize = beginning.size();
    int CSize = beginning[0].size();


    vector<vector<int>> v;
    // 2 ^ RSize ��ŭ ����
    for (int i = 0; i < (2 << RSize); i++) {
        int count = 0;
        v.clear();
        v.assign(beginning.begin(), beginning.end());
        for (int row = 0; row < RSize; row++) {
            // row ��Ʈ�� 1�̸� ������ 0�̸� �ȵ����´�.
            if ((i & (2 << row)) == 0) continue;
            flipRow(v, row);
            count++;
        }

        bool Okay = true;
        for (int c = 0; c < CSize; c++) {
            // ��� target�� ���� ���̰ų� ��� �ٸ� ���� ��츸
            // ��ǥ ���� ����� ����! �� ������ ���� ���� Ż��!
            // ���� ��� �ٸ� ���� ���� ��������ϴ� count �ϳ� �÷�����!
            bool tf = (v[0][c] == target[0][c]) ? true : false;
            for (int r = 1; r < RSize; r++) {
                if (tf != (v[r][c] == target[r][c]) ? true : false) {
                    Okay = false;
                    break;
                }
            }
            if (!Okay) {
                break;
            }
            else {
                if (!tf)
                    count++;
            }
        }
        if (Okay)
            answer = min(count, answer);

    }
    // answer ���� ������ �ʾ����� ��ǥ ���¸� ������ ���ϴ� ���
    if(answer == 9999999)
        return -1;

    return answer;
}

int main() {

    printf("%d\n", solution({ {0, 1, 0, 0, 0 }, { 1, 0, 1, 0, 1 }, { 0, 1, 1, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 1, 0 } },
        { {0, 0, 0, 1, 1},{0, 0, 0, 0, 1},{0, 0, 1, 0, 1},{0, 0, 0, 1, 0},{0, 0, 0, 0, 1} }));    
    //printf("%d\n", solution({ {1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1} },
    //    { {1, 0, 1, 1},{0, 1, 1, 1},{1, 1, 1, 0},{0, 0, 1, 0} }));
    return 0;
}
*/