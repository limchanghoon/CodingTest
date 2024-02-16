#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<string, int> dic_SI;
	vector<string> vec;
	vec.push_back("?");
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;
		vec.push_back(s);
		dic_SI.insert({ s,i });
	}

	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;
		if (('0' <= s[0] && s[0] <= '9')) 
			cout << vec[stoi(s)]<<"\n";
		else
			cout << dic_SI[s] << "\n";
	}
	return 0;
}