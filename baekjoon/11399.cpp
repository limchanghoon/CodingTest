#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, sum = 0,answer=0;
	cin >> N;
	vector<int> table(N);
	for (int i = 0; i < N; ++i)
		cin >> table[i];
	sort(table.begin(), table.end());
	for (int i = 0; i < N; ++i) {
		sum += table[i];
		answer += sum;
	}
	cout << answer;
	return 0;
}