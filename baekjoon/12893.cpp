#include <iostream>

using namespace std;

int N, M;
int parent[2001];
int parent_enemy[2001];

int getParent(int x) {
	if (parent[x] != x) parent[x] = getParent(parent[x]);
	return parent[x];
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x > y) parent[x] = y;
	else parent[y] = x;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int answer = 1;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int A, B;
		cin >> A >> B;
		if (parent_enemy[A] == 0) parent_enemy[A] = B;
		if (parent_enemy[B] == 0) parent_enemy[B] = A;

		unionParent(A, parent_enemy[B]);
		unionParent(B, parent_enemy[A]);

		if (getParent(A) == getParent(B)) {
			answer = 0;
			break;
		}
	}

	cout << answer;

	return 0;
}