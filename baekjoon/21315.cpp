#include <iostream>

using namespace std;

int N;
int result[1000];
int card[1000];

void innerShuffle(int start, int count) {
	int newCard[1000];
	for (int i = 0; i < count; ++i) {
		newCard[i] = card[start + i];
	}

	int index = count;
	for (int i = 0; i < N; ++i) {
		if (i < start || i >= start + count) {
			newCard[index++] = card[i];
		}
		card[i] = newCard[i];
	}
}

void shuffle(int k) {
	int sz = N;
	for (int i = k; i >= 0; --i) {
		int count = (1 << i);
		innerShuffle(sz - count, count);
		sz = count;
	}
}

void resetCard() {
	for (int i = 0; i < N; ++i)
		card[i] = i + 1;
}

bool checkCard(int i, int j) {
	for (int k = 0; k < N; ++k) {
		if (card[k] != result[k])
			return false;
		if (k == N - 1) {
			cout << i << " " << j;
			return true;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> result[i];
	}

	for (int i = 1; (1 << i) <= N; ++i) {
		for (int j = 1; (1 << j) <= N; ++j) {
			resetCard();
			shuffle(i);
			shuffle(j);
			if (checkCard(i, j))
				return 0;
		}
	}
	return 0;
}
