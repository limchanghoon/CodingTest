#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int ans = 0, N;
	cin >> N;
	vector<int> sequence(N);
	vector<int> table(N);
	for (int i = 0; i < N; ++i) {
		cin >> sequence[i];
		table[i] = sequence[i];
	}

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < i; ++j)
			if (sequence[i] > sequence[j])
				table[i] = max(table[j] + sequence[i], table[i]);
		ans = max(ans, table[i]);
	}
	cout << ans;
	return 0;
}