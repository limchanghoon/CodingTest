#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, ans = 0;
	cin >> N >> M;
	vector<int> materials(N);
	for (int i = 0; i < N; ++i)
		cin >> materials[i];
	sort(materials.begin(), materials.end());

	int pre = 0, post = N - 1;
	while (pre < post) {
		int sum = materials[pre] + materials[post];
		if (sum == M) {
			++ans;
			++pre;
			--post;
		}
		else if (sum < M)
			++pre;
		else
			--post;
	}
	cout << ans;
	return 0;
}