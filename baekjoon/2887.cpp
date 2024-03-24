#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct MyStruct {
	int a, b;
	int cost;
};

int N;
vector<pair<int, int>> tableX;
vector<pair<int, int>> tableY;
vector<pair<int, int>> tableZ;
vector<int> parents;
vector<MyStruct> vec;

int getParent(int x) {
	if (x == parents[x]) return x;
	return parents[x] = getParent(parents[x]);
}

void merge(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px < py) parents[py] = px;
	else parents[px] = py;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long answer = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		parents.push_back(i);
		tableX.push_back({ i,x });
		tableY.push_back({ i,y });
		tableZ.push_back({ i,z });
	}

	sort(tableX.begin(), tableX.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second; });
	sort(tableY.begin(), tableY.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second; });
	sort(tableZ.begin(), tableZ.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second; });

	for (int i = 0; i < N - 1; ++i) {
		vec.push_back({ tableX[i].first ,tableX[i + 1].first ,abs(tableX[i].second - tableX[i + 1].second) });
		vec.push_back({ tableY[i].first ,tableY[i + 1].first ,abs(tableY[i].second - tableY[i + 1].second) });
		vec.push_back({ tableZ[i].first ,tableZ[i + 1].first ,abs(tableZ[i].second - tableZ[i + 1].second) });
	}

	sort(vec.begin(), vec.end(), [](const MyStruct& a, const MyStruct& b) {return a.cost < b.cost; });

	for (int i = 0; i < vec.size(); ++i) {
		if (getParent(vec[i].a) == getParent(vec[i].b)) continue;
		merge(vec[i].a, vec[i].b);
		answer += vec[i].cost;
		if (--N == 1) {
			cout << answer;
			return 0;
		}
	}

	return 0;
}