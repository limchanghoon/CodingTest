#include <iostream>

using namespace std;

int N;
long long K;
int table[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long sum = 0;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> table[i];
		sum += table[i];
		if (sum > K) {
			cout << i;
			return 0;
		}
	}

	for (int i = N; i >= 0; --i) {
		sum += table[i];
		if (sum > K) {
			cout << i;
			return 0;
		}
	}

	return 0;
}