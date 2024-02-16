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
        if (curDq[orders[i]] == true)  // 코드 O
        {
            // 그냥 넘어감
        }
        else if (curVc.size() < N)  // 빈자리 O
        {
            curVc.push_back(orders[i]);
            curDq[orders[i]] = true;
        }
        else if (curDq[orders[i]] == false)    // 코드 X
        {
            // 1순위 : 사용 안하는 코드
            // 2순위 : 제일 마지막 사용하는 코드 
            int targetIdx = 0;
            int pos = -1;
            for (int j = 0; j < N; ++j)
            {
                bool End = false;
                for (int k = i + 1; k < K; ++k)
                {
                    if (curVc[j] == orders[k])  // 뒤에 나왔음
                    {
                        if (pos < k) // 기존 찾은 코드보다 더 뒤에 있으면
                        {
                            pos = k;
                            targetIdx = j;
                        }
                        break;
                    }

                    if (k == K - 1)// 사용 안하는 코드 찾음
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