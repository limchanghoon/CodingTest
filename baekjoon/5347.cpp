#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) {
		long long temp = a;
		a = b;
		b = temp;
	}

	if (a % b == 0) return b;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		long long a, b;
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}

	return 0;
}