#include <iostream>
#include <vector>

using namespace std;

string search(vector<pair<int, string>>& table, int power) {
	string ans = "";
	int bottom = 0, top = table.size() - 1, mid;
	while (bottom <= top) {
		mid = (bottom + top) / 2;

		int curPower = table[mid].first;

		if (curPower >= power) {
			top = mid - 1;
			ans = table[mid].second;
		}
		else
			bottom = mid + 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<pair<int, string>> table(N);
	for (int i = 0; i < N; ++i) {
		cin >> table[i].second;
		cin >> table[i].first;
	}
	for (int i = 0; i < M; ++i) {
		int power;
		cin >> power;
		cout << search(table, power) << "\n";
	}
	return 0;
}