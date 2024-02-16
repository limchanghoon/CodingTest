#include <iostream>
#include <algorithm>

#define MYMAX 40000004

using namespace std;


int V, E;
int edges[401][401];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int answer = MYMAX;
	cin >> V >> E;

	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j)	continue;
			edges[i][j] = MYMAX;
		}
	}

	for (int i = 0; i < E; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		edges[a][b] = c;
	}

	//j => i => k
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j)	continue;
			for (int k = 1; k <= V; ++k) {
				if (j == k || k == i)	continue;
				edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j)	continue;
			answer = min(answer, edges[i][j] + edges[j][i]);
		}
	}
	if (answer == MYMAX)
		answer = -1;
	cout << answer;
	return 0;
}