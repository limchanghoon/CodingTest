#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<string, int> myMap;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)	// 길이가 M이상인 단어들의 등장 횟수 저장
	{
		string s;
		cin >> s;
		if (s.size() < M)
			continue;
		++myMap[s];
	}

	vector<pair<string, int>> myVector(myMap.begin(), myMap.end());
	sort(myVector.begin(), myVector.end(), [](pair<string, int>& a, pair<string, int>& b) {
		if (a.second != b.second)
			return a.second > b.second;				// 1.자주 나오는 단어일수록 앞에 배치한다.
		else if (a.first.size() != b.first.size())
			return a.first.size() > b.first.size();	// 2.해당 단어의 길이가 길수록 앞에 배치한다.
		else
			return a.first < b.first;				// 3.알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
		});

	for (int i = 0; i < myVector.size(); ++i)
		cout << myVector[i].first << "\n";
	return 0;
}