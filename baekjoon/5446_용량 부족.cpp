#include <iostream>
#include <string>
#include <map>

using namespace std;

int answer = 0;

struct trie {
	map<char, trie*> next;
	bool isRoot = false;
	bool isEnd = false;
	bool isDeleted = false;
public:
	void Add(const string& str) {
		if (next.count(str[0]) == 0)
			next.insert({ str[0] ,new trie() });

		if (str.size() == 1)
			next[str[0]]->isEnd = true;
		else
			next[str[0]]->Add(str.substr(1));
	}

	void Delete(const string& str) {
		if (next.count(str[0]) == 0)
			return;

		next[str[0]]->isDeleted = true;
		if (next[str[0]]->isEnd)
			answer++;
		if (str.size() > 1)
			next[str[0]]->Delete(str.substr(1));
	}

	void search() {
		if (isEnd && isDeleted)
			answer++;

		if (!isDeleted) {
			answer++;
			return;
		}
		for (auto iter = next.begin(); iter != next.end(); iter++) {
			iter->second->search();
		}
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	while (T--)
	{
		trie root;
		root.isRoot = true;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			string str;
			cin >> str;
			root.Add(str);
		}

		int M;
		cin >> M;
		for (int i = 0; i < M; ++i) {
			string str;
			cin >> str;
			root.Delete(str);
		}

		// * 와일드카드 체크
		for (auto iter = root.next.begin(); iter != root.next.end(); iter++) {
			if (iter->second->isDeleted) {
				root.isDeleted = true;
				break;
			}
		}

		answer = 0;
		root.search();

		cout << answer << "\n";
	}

	return 0;
}