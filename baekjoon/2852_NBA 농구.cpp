#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[1] < b[1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>> goals(N + 1, vector<int>(2));
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> goals[i][0];
		cin >> s;
		goals[i][1] = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
	}
	goals[N] = { 0,48 * 60 }; // 마지막 시간까지 판단하기 위해 넣어준다.

	sort(goals.begin(), goals.end(), cmp);

	int cnt = 0; // 1팀 기준 골득실
	int preS = 0, team_1 = 0, team_2 = 0;
	for (int i = 0; i < N + 1; ++i)
	{
		int dis = goals[i][1] - preS;
		if (cnt > 0)
			team_1 += dis;
		else if (cnt < 0)
			team_2 += dis;

		if (goals[i][0] == 1)
			++cnt;
		else if (goals[i][0] == 2)
			--cnt;

		preS = goals[i][1];
	}

	cout << setw(2) << setfill('0') << team_1 / 60 << ":" << setw(2) << setfill('0') << team_1 % 60 << "\n"
		<< setw(2) << setfill('0') << team_2 / 60 << ":" << setw(2) << setfill('0') << team_2 % 60;
	return 0;
}