#include <iostream>

using namespace std;

int N, M;
bool OK = false;

int answer[16];
bool visited[16];
int likeability[16][5];
int favorite[16][2];
int tong[16][16];

void dfs(int frog) {
	if (frog > N) {
		OK = true;
		return;
	}
	for (int i = 0; i < 2; ++i) {
		int des = favorite[frog][i];
		if (visited[des])	continue;

		int j = 1;
		for (; j <= N; ++j) {
			if (!visited[j])	continue;
			int frog2 = answer[j];
			int subject = tong[des][j];
			if (likeability[frog][subject] != likeability[frog2][subject])	break;
		}
		if (j != N + 1)	continue;

		answer[des] = frog;
		visited[des] = true;
		dfs(frog + 1);
		if (OK)	return;
		visited[des] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		cin >> likeability[i][1] >> likeability[i][2] >> likeability[i][3] >> likeability[i][4];
	}

	for (int i = 1; i <= N; ++i) {
		cin >> favorite[i][0] >> favorite[i][1];
	}

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		tong[a][b] = c;
		tong[b][a] = c;
	}

	dfs(1);

	if (OK) {
		cout << "YES" << "\n";
		for (int i = 1; i <= N; ++i)
			cout << answer[i] << " ";
	}
	else {
		cout << "NO";
	}

	return 0;
}