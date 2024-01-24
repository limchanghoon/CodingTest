#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct three {
	int num, depth;
	vector<int> pres;
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> visited(N + 1);
	queue<three> q;

	q.push({ N,-1,{} });
	while (!q.empty()) {
		int num = q.front().num, depth = q.front().depth + 1;
		vector<int> pres = q.front().pres;
		pres.push_back(num);
		q.pop();

		if (visited[num] != 0)
			continue;
		visited[num] = 1;


		if (num == 1) {
			cout << depth << "\n";
			for (auto i : pres)
				cout << i << " ";
			break;
		}

		if (num % 3 == 0 && visited[num / 3] == 0)
			q.push({ num / 3, depth, pres });
		if (num % 2 == 0 && visited[num / 2] == 0)
			q.push({ num / 2, depth, pres });
		if (visited[num - 1] == 0)
			q.push({ num - 1, depth, pres });
	}

	return 0;
}