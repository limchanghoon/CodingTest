#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main() {
    int result = 0;

    int N, K;
    vector<int> orders;

    cin >> N >> K;

    for (int i = 0; i < K; ++i)
    {
        int n;
        cin >> n;
        orders.push_back(n);
    }

    vector<int> curVc;
    deque<bool> curDq(K + 1);

    // 2 3 2 3 1 2 7
    for (int i = 0; i < K; ++i)
    {
        if (curDq[orders[i]] == true)  // �ڵ� O
        {
            // �׳� �Ѿ
        }
        else if (curVc.size() < N)  // ���ڸ� O
        {
            curVc.push_back(orders[i]);
            curDq[orders[i]] = true;
        }
        else if (curDq[orders[i]] == false)    // �ڵ� X
        {
            // 1���� : ��� ���ϴ� �ڵ�
            // 2���� : ���� ������ ����ϴ� �ڵ� 
            int targetIdx = 0;
            int pos = -1;
            for (int j = 0; j < N; ++j)
            {
                bool End = false;
                for (int k = i + 1; k < K; ++k)
                {
                    if (curVc[j] == orders[k])  // �ڿ� ������
                    {
                        if (pos < k) // ���� ã�� �ڵ庸�� �� �ڿ� ������
                        {
                            pos = k;
                            targetIdx = j;
                        }
                        break;
                    }

                    if (k == K - 1)// ��� ���ϴ� �ڵ� ã��
                    {
                        targetIdx = j;
                        End = true;
                        break;
                    }
                }
                if (End)
                    break;
            }


            curDq[curVc[targetIdx]] = false;
            curVc[targetIdx] = orders[i];
            curDq[orders[i]] = true;
            ++result;
        }
            
    }

    cout << result << endl;

    return 0;
}