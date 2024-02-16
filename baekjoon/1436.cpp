#include <iostream>

using namespace std;

bool check(int num) {
	while (num >= 666) {
		if (num % 1000 == 666)
			return true;
		num /= 10;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int count = 0;
	for (int i = 666; true; ++i) {
		if (check(i))
			++count;
		if (count == N) {
			cout << i;
			return 0;
		}
	}
	return 0;
}