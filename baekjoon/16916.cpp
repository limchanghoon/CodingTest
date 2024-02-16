
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string p) {
    int m = (int)p.size(), j = 0;
    vector<int> table(m, 0);

    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = table[j - 1];

        if (p[i] == p[j])
            table[i] = ++j;

    }
    return table;

}

int kmp(string s, string p) {
    auto table = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = table[j - 1];

        if (s[i] == p[j]) {
            if (j == m - 1) {
                return 1;
            }
            else {
                j++;
            }
        }
    }
    return 0;
}


int main()
{
	string S;
	string P;

	cin >> S >> P;

    cout << kmp(S, P) << endl;
}
