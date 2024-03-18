/*
*  트라이구조
* 
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;

struct TrieNode {
public :
	map<char, TrieNode*> m_Map;
	bool isWord = false;

	~TrieNode() {
		for (auto& [i, _] : m_Map) delete m_Map[i];
	}
	
	void Add(const char* cStr) {
		int next = *cStr;
		if (next == NULL) {
			isWord = true;
			return;
		}
		if (m_Map.find(next) == m_Map.end()) {
			m_Map[next] = new TrieNode();
		}
		m_Map[next]->Add(cStr + 1);
	}

	bool Search(const char* cStr) {
		int next = *cStr;
		if (next == NULL) return isWord;
		if (m_Map.find(next) == m_Map.end()) return false;
		return m_Map[next]->Search(cStr + 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans = 0;
	TrieNode* root = new TrieNode();
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		root->Add(str.c_str());
	}
	for (int i = 0; i < M; ++i) {
		string str;
		cin >> str;
		if (root->Search(str.c_str())) ans++;
	}
	cout << ans;

	delete root;
	return 0;
}
*/

// 이분탐색

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans = 0;
	vector<string> vec;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < M; ++i) {
		string str; cin >> str;
		int left = 0, right = vec.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (vec[mid] == str) {
				ans++;
				break;
			}
			else if (vec[mid] < str) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	cout << ans;

	return 0;
}