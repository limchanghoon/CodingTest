#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long N, K;
	long long sum = 0, ans = 0;
	map<long long, int> myMap;

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		long long temp;
		cin >> temp;
		sum += temp;
		long long temp2 = sum - i * K;

		if (temp2 == 0) ans++;
		ans += myMap[temp2];
		myMap[temp2]++;
	}
	cout << ans;

	return 0;
}