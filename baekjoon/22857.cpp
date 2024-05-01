#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int table[50000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) 
		cin >> table[i];
	
	int answer = 0, even = 0, odd = 0, p2 = 0;

	for (int i = 0; i < N; ++i) {
		if (table[i] % 2 == 0) {
			answer = max(answer, ++even);
		}
		else {
			++odd;
			while (odd > K) {
				if (table[p2] % 2 == 0) --even;
				else --odd;
				++p2;
			}
		}
	}
	cout << answer;
	return 0;
}