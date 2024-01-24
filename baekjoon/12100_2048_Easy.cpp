#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, answer = 0;
vector<vector<int>> table;
deque<deque<bool>> visited;

void resetVisited()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			visited[i][j] = false;
}

void moveRight() {
	for (int i = 0; i < N; ++i) {
		for (int j = N - 2; j >= 0; --j) {
			int temp = table[i][j];
			if (temp == 0)
				continue;
			table[i][j] = 0;
			for (int k = j + 1; k < N; ++k) {
				if (temp != table[i][k] && table[i][k] != 0) {
					table[i][k - 1] = temp;
					break;
				}
				if (temp == table[i][k]) {
					if (visited[i][k]) {
						table[i][k - 1] = temp;
						break;
					}
					table[i][k] *= 2;
					answer = max(answer, table[i][k]);
					visited[i][k] = true;
					break;
				}
				if (k == N - 1) {
					table[i][k] = temp;
				}
			}
		}
	}
}

void moveLeft() {
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			int temp = table[i][j];
			if (temp == 0)
				continue;
			table[i][j] = 0;
			for (int k = j - 1; k >= 0; --k) {
				if (temp != table[i][k] && table[i][k] != 0) {
					table[i][k + 1] = temp;
					break;
				}
				if (temp == table[i][k]) {
					if (visited[i][k]) {
						table[i][k + 1] = temp;
						break;
					}
					table[i][k] *= 2;
					answer = max(answer, table[i][k]);
					visited[i][k] = true;
					break;
				}
				if (k == 0) {
					table[i][k] = temp;
				}
			}
		}
	}
}

void moveDown() {
	for (int i = 0; i < N; ++i) {
		for (int j = N - 2; j >= 0; --j) {
			int temp = table[j][i];
			if (temp == 0)
				continue;
			table[j][i] = 0;
			for (int k = j + 1; k < N; ++k) {
				if (temp != table[k][i] && table[k][i] != 0) {
					table[k - 1][i] = temp;
					break;
				}
				if (temp == table[k][i]) {
					if (visited[k][i]) {
						table[k - 1][i] = temp;
						break;
					}
					table[k][i] *= 2;
					answer = max(answer, table[k][i]);
					visited[k][i] = true;
					break;
				}
				if (k == N - 1) {
					table[k][i] = temp;
				}
			}
		}
	}
}

void moveUp() {
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			int temp = table[j][i];
			if (temp == 0)
				continue;
			table[j][i] = 0;
			for (int k = j - 1; k >= 0; --k) {
				if (temp != table[k][i] && table[k][i] != 0) {
					table[k + 1][i] = temp;
					break;
				}
				if (temp == table[k][i]) {
					if (visited[k][i]) {
						table[k + 1][i] = temp;
						break;
					}
					table[k][i] *= 2;
					answer = max(answer, table[k][i]);
					visited[k][i] = true;
					break;
				}
				if (k == 0) {
					table[k][i] = temp;
				}
			}
		}
	}
}

void dfs(int count) {
	if (count-- == 0)
		return;

	vector<vector<int>> origin(table);
	
	resetVisited();
	moveRight();
	dfs(count);
	table = origin;

	resetVisited();
	moveLeft();
	dfs(count);
	table = origin;

	resetVisited();
	moveDown();
	dfs(count);
	table = origin;
	
	resetVisited();
	moveUp();
	dfs(count);
	table = origin;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	table.resize(N, vector<int>(N));
	visited.resize(N, deque<bool>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			answer = max(answer, table[i][j]);
		}
	}
	dfs(5);



	cout << answer;
	return 0;
}