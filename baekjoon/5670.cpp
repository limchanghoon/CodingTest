#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n;

class TrieNode {
public:
	map<char, TrieNode*> child;
	int count = 0;
public:
	void Add(const string& str) {
		char c = str[0];
		if (child.count(c) == 0)
			child.insert({ c, new TrieNode() });
		child[c]->count++;
		if (str.size() > 1)
			child[c]->Add(str.substr(1));
	}

	int GetAnswer(const string& str)
	{
		return child[str[0]]->GetAnswer(str, 0);
	}

private:
	int GetAnswer(const string& str, int pre)
	{
		int answer = 0;
		if (pre != count)
			answer++;
		if (str.size() > 1)
			answer += child[str[1]]->GetAnswer(str.substr(1), count);
		return answer;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin >> n) {
		TrieNode trie;
		vector<string> vec;
		string str;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			trie.Add(str);
			vec.push_back(str);
		}

		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += trie.GetAnswer(vec[i]);
		}

		cout << fixed;
		cout.precision(2);
		cout << round(((float)sum / n) * 100) / 100 << endl;


	}
	return 0;
}