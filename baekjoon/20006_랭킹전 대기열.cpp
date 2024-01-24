#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int level;
	string name;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<info>> rooms;
	int p, m;
	cin >> p >> m;
	for (int i = 0; i < p; ++i) {
		bool check = false;
		int level;
		string name;
		cin >> level >> name;
		for (int i = 0; i < rooms.size(); ++i) {
			if (rooms[i].size() >= m)
				continue;
			if (rooms[i][0].level - 10 <= level && level <= rooms[i][0].level + 10) {
				rooms[i].push_back({ level,name });
				check = true;
				break;
			}
		}

		if (!check)
			rooms.push_back({ info{level, name} });
	}

	for (int i = 0; i < rooms.size(); ++i) {
		sort(rooms[i].begin(), rooms[i].end(), [](const info& a, const info& b) {return a.name < b.name; });
		if (rooms[i].size() == m)
			cout << "Started!" << "\n";
		else
			cout << "Waiting!" << "\n";
		for (int j = 0; j < rooms[i].size(); ++j)
			cout << rooms[i][j].level << " " << rooms[i][j].name << "\n";
	}

	return 0;
}