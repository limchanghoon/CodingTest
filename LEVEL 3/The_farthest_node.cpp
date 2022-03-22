#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int BigNumber = 99999;

bool cmp(vector<int> a, vector<int> b) {
	return (a.front() < b.front());
}

void searchNode(bool* checkNode, int* results, vector<vector<int>> &ev, int n, int node,queue<int> &q) {

	for (int i = 0; i < ev[node].size(); i++) {
		
		if (checkNode[ev[node][i]] == false) {
			q.push(ev[node][i]);
			results[ev[node][i]] = min(results[node] + 1, results[ev[node][i]]);

		}
		
	}
	while (!q.empty()) {
		if (checkNode[q.front()] == true) {
			q.pop();
		}
		else
		{
			break;
		}
	}
	if (!q.empty()) {
		int temp = q.front();
		q.pop();
		checkNode[temp] = true;
		searchNode(checkNode, results, ev, n, temp, q);
	}


}

int solution(int n, vector<vector<int>> edge) {
	queue<int> q;
	bool* checkNode = new bool[n + 1];
	int* results = new int[n + 1];
	for (int i = 0; i < (n + 1); i++) {
		checkNode[i] = false;
		results[i] = BigNumber;
	}
	checkNode[1] = true;
	results[1] = 0;

	
	//sort(edge.begin(), edge.end(), cmp);

	vector<vector<int>> ev(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		ev[edge[i][0]].push_back(edge[i][1]);
		ev[edge[i][1]].push_back(edge[i][0]);
	}


	searchNode(checkNode, results, ev, n, 1,q);


	int largest = -1;
	for (int i = 1; i < (n + 1); i++) {
		if(results[i] != BigNumber)
			largest = max(largest, results[i]);
	}

	int answer = 0;
	for (int i = 1; i < n + 1; i++) {
		if (results[i] == largest)
			answer++;
	}


	return answer;
}


/*

int main() {
	// {1,3},{1,2},{2,4},{3,6},{3,2},{4,3},{5,2}
	printf("%d\n", solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} }));
	return 0;
}

*/