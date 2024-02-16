#include <iostream>
#include <vector>

using namespace std;

vector<string> vec;
bool arr[26];
int N, K;
int Answer = 0;

void Check()
{
    int cnt = 0;
    //a n t i c
    if (!arr['a' - 'a'] || !arr['n' - 'a'] || !arr['t' - 'a'] || !arr['i' - 'a'] || !arr['c' - 'a'])
        return;

    for (int i = 0; i < vec.size(); ++i)
    {
        bool can = true;
        for (int j = 0; j < vec[i].size(); ++j)
        {
            if (arr[vec[i][j] - 'a'] == false)
            {
                can = false;
                break;
            }
        }
        if (can)
            ++cnt;
    }
    Answer = max(Answer, cnt);
}

void DFS(int start, int depth)
{
    int cnt = 0;
    if (depth == K)
    {
        Check();
        return;
    }
    for (int i = start; i < 26; ++i)
    {
        arr[i] = true;
        DFS(i + 1, depth + 1);
        arr[i] = false;
    }
}


void solve()
{
    //a n t i c
    if (K < 5)
        return;

    for (int i = 0; i < 26; ++i)
        arr[i] = false;

    DFS(0, 0);
}


int main() {
    int result = 0;

    string S;

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> S;
        vec.push_back(S);
    }

    solve();
    cout << Answer << endl;
    return 0;
}