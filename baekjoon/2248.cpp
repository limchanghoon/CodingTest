#include <iostream>
#include <string>

using namespace std;

string solve(int N, int L, long long I, long long dp[][33]) {
    if (N == 0)
        return "";
    string result = "";
    long long count = 0;
    for (int i = 0; i <= L; ++i)
        count += dp[N - 1][i];
    
    if (count < I) {
        result += "1";
        result += solve(N - 1, L - 1, I - count, dp);
    }
    else {
        result += "0";
        result += solve(N - 1, L, I, dp);
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long dp[33][33] = { 0, };
    int N, L;
    long long I;
    cin >> N >> L >> I;
    for (int i = 0; i < 33; ++i)
        dp[i][0] = 1;

    for (int i = 1; i < 33; ++i) // 자리수
        for (int j = 1 ; j <= i; ++j) // 1의 개수
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

    cout << solve(N, L, I, dp);
    return 0;
}
/*
 0 : 1
 1 : 1 1
 2 : 1 2  1
 3 : 1 3  3  1
 4 : 1 4  6  4  1
 5 : 1 5 10 10  5  1
*/