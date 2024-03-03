#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define NotFound 999999999

using namespace std;

int answer = NotFound;
int maxCosts[100001];
int N, M, A, B, C;
vector<vector<pair<int, int>>> vec;

struct MyStruct {
	int cost, pos, maxC;
};

struct CMP {
	bool operator() (MyStruct a, MyStruct b) {
		return a.cost > b.cost;
	}
};

void dij() {
	priority_queue<MyStruct, vector<MyStruct>, CMP> pq;
	pq.push({ 0,A,0 });
	maxCosts[A] = 0;
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (cur.pos == B) {
			answer = min(answer, cur.maxC);
			continue;
		}

		if (maxCosts[cur.pos] < cur.maxC)	continue;

		for (int i = 0; i < vec[cur.pos].size(); ++i) {
			int nextPos = vec[cur.pos][i].first;
			int nextCost = cur.cost + vec[cur.pos][i].second;
			int nextMax = max(cur.maxC, vec[cur.pos][i].second);
			if (maxCosts[nextPos] <= nextMax || nextCost > C)	continue;
			pq.push({ nextCost, nextPos, nextMax });
			maxCosts[nextPos] = nextMax;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i <= N; ++i)	
		maxCosts[i] = NotFound;
	vec.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}
	dij();
	if (answer == NotFound) cout << -1;
	else cout << answer;
	return 0;
}