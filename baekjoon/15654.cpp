#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int table[8];
bool check[8];
vector<int> vec;
int N, M;

void gen(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << vec[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (check[i])	continue;
		check[i] = true;
		vec.push_back(table[i]);
		gen(depth + 1);
		vec.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}
	sort(table, table + N);
	gen(0);
	return 0;
}