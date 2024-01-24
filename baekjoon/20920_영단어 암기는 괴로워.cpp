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
	for (int i = 0; i < N; ++i)	// ���̰� M�̻��� �ܾ���� ���� Ƚ�� ����
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
			return a.second > b.second;				// 1.���� ������ �ܾ��ϼ��� �տ� ��ġ�Ѵ�.
		else if (a.first.size() != b.first.size())
			return a.first.size() > b.first.size();	// 2.�ش� �ܾ��� ���̰� ����� �տ� ��ġ�Ѵ�.
		else
			return a.first < b.first;				// 3.���ĺ� ���� ������ �տ� �ִ� �ܾ��ϼ��� �տ� ��ġ�Ѵ�
		});

	for (int i = 0; i < myVector.size(); ++i)
		cout << myVector[i].first << "\n";
	return 0;
}