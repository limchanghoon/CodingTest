#include <iostream>
#include <vector>

using namespace std;

int main() {
    int result = 0;

    int H, W;
    int n;
    vector<int> vec;

    cin >> H >> W;

    do {
        cin >> n;
        vec.push_back(n);
    } while (getc(stdin) == ' ');


    for (int i = 1; i <= H; ++i)
    {
        int pre = -1;
        for (int j = 0; j < W; ++j)
        {
            if (vec[j] >= i)
            {
                if (pre != -1)
                    result += j - pre - 1;

                pre = j;
            }
        }
    }

    cout << result << endl;

    return 0;
}