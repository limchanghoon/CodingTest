#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, int> myMap;
	int N, M, K;
	int ans = 0;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		if (myMap.find(str) == myMap.end()) {
			myMap.insert({ str,1 });
		}
		else {
			myMap[str]++;
		}
	}
	cin >> K;
	for (auto item : myMap) {
		int cnt = 0;
		for (int i = 0; i < item.first.length(); ++i) {
			if (item.first[i] == '0') cnt++;
		}
		if (cnt <= K && (K - cnt) % 2 == 0) {
			ans = max(ans, item.second);
		}
	}

	cout << ans;

	return 0;
}