/*

#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

set<pair<int,int>> oneWays[50001];	// {다음 노드, 시간}
char nodes[50001];					// R: 쉼터, G: 입출구, S:산봉우리
int costs[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	queue<pair<int, int>> q;			// {현재 위치, 지금까지 시간}
	// 노드는 R: 쉼터, G: 입출구, S:산봉우리 으로 구분함.
	// costs[]에 큰값을 초기값으로 저장함.
	for (int i = 1; i <= n; i++) {
		nodes[i] = 'R';
		costs[i] = 10000001;
	}
	
	for (int i = 0; i < summits.size(); i++) {
		nodes[summits[i]] = 'S';
	}

	// 입출구에서 시작하니 q에 넣음. 그리고 시작점이니 지금까지의 cost는 0임.
	for (int i = 0; i < gates.size(); i++) {
		q.push({ gates[i], 0 });
		costs[gates[i]] = 0;
		nodes[gates[i]] = 'G';
	}


	for (int i = 0; i < paths.size(); i++) {
		if ((nodes[paths[i][0]] == 'R' && nodes[paths[i][1]] == 'S') || (nodes[paths[i][0]] == 'G' && nodes[paths[i][1]] == 'R') || (nodes[paths[i][0]] == 'G' && nodes[paths[i][1]] == 'S')) 
		{	// R -> S, G -> R, G -> S 이는 왼쪽에서 오른쪽으로만 이동 가능
			oneWays[paths[i][0]].insert({ paths[i][1], paths[i][2] });
		}
		else if ((nodes[paths[i][0]] == 'R' && nodes[paths[i][1]] == 'G') || (nodes[paths[i][0]] == 'S' && nodes[paths[i][1]] == 'R') || (nodes[paths[i][0]] == 'S' && nodes[paths[i][1]] == 'G')) 
		{	// R <- G, S <- R, S <- G 이는 오른쪽에서 왼족으로만 이동 가능
			oneWays[paths[i][1]].insert({ paths[i][0], paths[i][2] });
		}
		else if (nodes[paths[i][0]] == 'R' && nodes[paths[i][1]] == 'R')
		{	// R <-> R 이는 양쪽으로 이동 가능
			oneWays[paths[i][0]].insert({ paths[i][1], paths[i][2] });
			oneWays[paths[i][1]].insert({ paths[i][0], paths[i][2] });
		}
	}

	// q를 모두 돈다. (일단 입구부터 시작해서 경로를 q에 넣는다.)
	while (!q.empty())
	{
		int pos = q.front().first; 
		int cost = q.front().second;
		q.pop();

		// costs[pos] 보다 cost가 크다는 것은 costs[pos]가 최소 한번은 갱신됐다는 의미
		// 즉, 현재 costs[pos] 최소한 cost보다는 적은 cost를 사용함
		if (costs[pos] < cost) {
			continue;
		}

		if (nodes[pos] == 'S') {	// 봉우리 도착 현재 cost가 costs[봉우리]보다 작으면 저장
			if (costs[pos] > cost)
				costs[pos] = cost;
		}
		else  {	// 현재 위치(G or R)에서 다음 이동 경로로 이동. 현재  cost와 다음 위치의 costs[다음 위치]중 큰 것이 q에 들어가는 cost이다.
			for (auto x : oneWays[pos]) {
				if (costs[x.first] > max(cost, x.second)) {
					costs[x.first] = max(cost, x.second);
					q.push({ x.first, costs[x.first] });
				}
			}
			
		}
	}

	// 산봉우리 중에서 가장 작은 costs[]를 가지는 곳을 고름.(costs[]가 같으면 nummber가 작은 산봉우리 선택함)
	int intensity = 10000001; int number = 200001;
	for (int i = 0; i < summits.size(); i++) {
		if (intensity == costs[summits[i]] && number > summits[i]) {
			number = summits[i];
		}
		else if (intensity > costs[summits[i]]) {
			intensity = costs[summits[i]];
			number = summits[i];
		}
	}

	answer.push_back(number);
	answer.push_back(intensity);
	return answer;
}

int main() {
	vector<int> result = solution(7, { { 1,2,5 },{ 1,4,1 },{ 2,3,1 },{ 2,6,7 },{ 4,5,1 },{ 5,6,1 },{ 6,7,1 } }, { 3,7 }, { 1,5 });
	printf("Result : (%d , %d)\n", result[0], result[1]);
	return 0;
}

*/