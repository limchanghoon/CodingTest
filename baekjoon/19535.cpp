#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> vec;
int adjCount[300001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
		adjCount[a]++;
		adjCount[b]++;
	}


	int D = 0, G = 0;
	for (int i = 1; i <= N; ++i) {
		if (adjCount[i] >= 3)
			G += (adjCount[i]) * (adjCount[i] - 1) * (adjCount[i] - 2) / 6;
	}

	for (int i = 0; i < vec.size(); ++i) {
		D += (adjCount[vec[i].first] - 1) * (adjCount[vec[i].second] - 1);
	}

	if (D > G * 3)
		cout << "D";
	else if (D < G * 3)
		cout << "G";
	else
		cout << "DUDUDUNGA";

	return 0;
}