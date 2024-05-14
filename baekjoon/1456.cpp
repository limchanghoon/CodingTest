#include <iostream>
#include <cstring>

using namespace std;

const int limit = 10000000;
bool isPrime[limit + 1];

void findPrime() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= limit; ++i) {
		if (!isPrime[i]) continue;
		for (int j = i + i; j <= limit; j += i) {
			isPrime[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	findPrime();
	long long A, B;
	cin >> A >> B;

	long long cnt = 0;
	for (long long i = 2; i * i <= B; ++i) {
		if (!isPrime[i]) continue;
		long long temp = i;
		while (temp <= B / i) {
			temp *= i;
			if (A <= temp)
				++cnt;
		}
	}
	cout << cnt;
	return 0;
}