#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool visited[501];
vector<vector<int>> upVec;
vector<vector<int>> downVec;

int getParentCount(int cur) {
	if (visited[cur])	return 0;
	visited[cur] = true;

	int cnt = 1;
	for (int i = 0; i < upVec[cur].size(); ++i)
		cnt += getParentCount(upVec[cur][i]);

	return cnt;
}

int getChildCount(int cur) {
	if (visited[cur])	return 0;
	visited[cur] = true;

	int cnt = 1;
	for (int i = 0; i < downVec[cur].size(); ++i)
		cnt += getChildCount(downVec[cur][i]);

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int answer = 0;
	cin >> N >> M;
	upVec.resize(N + 1);
	downVec.resize(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		upVec[a].push_back(b);
		downVec[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i) {
		int temp = 0;
		memset(visited, false, sizeof(visited));
		temp += (getParentCount(i) - 1);
		memset(visited, false, sizeof(visited));
		temp += (getChildCount(i) - 1);
		if (temp == N - 1)
			++answer;
	}
	cout << answer;

	return 0;
}
