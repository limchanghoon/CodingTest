#include <iostream>

using namespace std;

int N;
int inOrderIndex[100001];
int inOrder[100001];
int postOrder[100001];

void Divid(int S_in, int S_post, int length) {
	if (length <= 0) return;

	int root = postOrder[S_post + length - 1];
	cout << root << " ";
	int preSz = inOrderIndex[root] - S_in;

	Divid(S_in, S_post, preSz);
	Divid(S_in + preSz + 1, S_post + preSz, length - preSz - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> inOrder[i];
		inOrderIndex[inOrder[i]] = i;
	}
	for (int i = 1; i <= N; ++i) {
		cin >> postOrder[i];
	}

	Divid(1, 1, N);

	return 0;
}