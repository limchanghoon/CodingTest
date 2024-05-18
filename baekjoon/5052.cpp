#include <iostream>
#include <map>

using namespace std;

class Trie {
public:
	map<char, Trie*> num;
	int count = 0;
	bool isEnd = false;

	~Trie() {
		for (auto iter = num.begin(); iter != num.end(); iter++) {
			delete iter->second;
		}
	}

	bool add(const string& str, int idx, bool ans) {
		count++;
		if (isEnd) ans = false;
		if (str.length() == idx) {
			isEnd = true;
			if (count > 1) ans = false;
			return ans;
		}
		if (num.count(str[idx]) == 0) {
			num.insert({ str[idx], new Trie() });
		}
		return num[str[idx]]->add(str, idx + 1, ans);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		Trie* t = new Trie();

		bool ans = true;
		int n;
		string str;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			if (!(t->add(str, 0, true)))
				ans = false;
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
		delete t;
	}
	return 0;
}