#include <iostream>
#include <vector>

using namespace std;



int main() {
    int answer = INT32_MAX;
    
    int N, S;

    cin >> N >> S;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        vec[i] = n;
    }

    int sum = 0;
    for (int cur = 0, pre = 0; cur < N; ++cur)
    {
        sum += vec[cur];

        while (sum >= S) {
            answer = min(answer, cur - pre + 1);

            if (pre < cur)
                sum -= vec[pre++];
            else // pre와 cur이 같으면 sum = vec[cur];
                break;
        }
    }

    if (answer == INT32_MAX)
        answer = 0;

    cout << answer << endl;

    return 0;
}