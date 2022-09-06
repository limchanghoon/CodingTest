/*

#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

set<pair<int,int>> oneWays[50001];	// {���� ���, �ð�}
char nodes[50001];					// R: ����, G: ���ⱸ, S:����츮
int costs[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	queue<pair<int, int>> q;			// {���� ��ġ, ���ݱ��� �ð�}
	// ���� R: ����, G: ���ⱸ, S:����츮 ���� ������.
	// costs[]�� ū���� �ʱⰪ���� ������.
	for (int i = 1; i <= n; i++) {
		nodes[i] = 'R';
		costs[i] = 10000001;
	}
	
	for (int i = 0; i < summits.size(); i++) {
		nodes[summits[i]] = 'S';
	}

	// ���ⱸ���� �����ϴ� q�� ����. �׸��� �������̴� ���ݱ����� cost�� 0��.
	for (int i = 0; i < gates.size(); i++) {
		q.push({ gates[i], 0 });
		costs[gates[i]] = 0;
		nodes[gates[i]] = 'G';
	}


	for (int i = 0; i < paths.size(); i++) {
		if ((nodes[paths[i][0]] == 'R' && nodes[paths[i][1]] == 'S') || (nodes[paths[i][0]] == 'G' && nodes[paths[i][1]] == 'R') || (nodes[paths[i][0]] == 'G' && nodes[paths[i][1]] == 'S')) 
		{	// R -> S, G -> R, G -> S �̴� ���ʿ��� ���������θ� �̵� ����
			oneWays[paths[i][0]].insert({ paths[i][1], paths[i][2] });
		}
		else if ((nodes[paths[i][0]] == 'R' && nodes[paths[i][1]] == 'G') || (nodes[paths[i][0]] == 'S' && nodes[paths[i][1]] == 'R') || (nodes[paths[i][0]] == 'S' && nodes[paths[i][1]] == 'G')) 
		{	// R <- G, S <- R, S <- G �̴� �����ʿ��� �������θ� �̵� ����
			oneWays[paths[i][1]].insert({ paths[i][0], paths[i][2] });
		}
		else if (nodes[paths[i][0]] == 'R' && nodes[paths[i][1]] == 'R')
		{	// R <-> R �̴� �������� �̵� ����
			oneWays[paths[i][0]].insert({ paths[i][1], paths[i][2] });
			oneWays[paths[i][1]].insert({ paths[i][0], paths[i][2] });
		}
	}

	// q�� ��� ����. (�ϴ� �Ա����� �����ؼ� ��θ� q�� �ִ´�.)
	while (!q.empty())
	{
		int pos = q.front().first; 
		int cost = q.front().second;
		q.pop();

		// costs[pos] ���� cost�� ũ�ٴ� ���� costs[pos]�� �ּ� �ѹ��� ���ŵƴٴ� �ǹ�
		// ��, ���� costs[pos] �ּ��� cost���ٴ� ���� cost�� �����
		if (costs[pos] < cost) {
			continue;
		}

		if (nodes[pos] == 'S') {	// ���츮 ���� ���� cost�� costs[���츮]���� ������ ����
			if (costs[pos] > cost)
				costs[pos] = cost;
		}
		else  {	// ���� ��ġ(G or R)���� ���� �̵� ��η� �̵�. ����  cost�� ���� ��ġ�� costs[���� ��ġ]�� ū ���� q�� ���� cost�̴�.
			for (auto x : oneWays[pos]) {
				if (costs[x.first] > max(cost, x.second)) {
					costs[x.first] = max(cost, x.second);
					q.push({ x.first, costs[x.first] });
				}
			}
			
		}
	}

	// ����츮 �߿��� ���� ���� costs[]�� ������ ���� ��.(costs[]�� ������ nummber�� ���� ����츮 ������)
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