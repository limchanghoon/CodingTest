#include <iostream>
#include <algorithm>

using namespace std;

class trie {
	trie* node[2];

public:
	~trie() {
		if (node[0] != nullptr) delete node[0];
		if (node[1] != nullptr) delete node[1];
	}

	void add(char* s) {
		if (*s == 0) return;
		int idx = *s - '0';
		if (node[idx] == nullptr) node[idx] = new trie();
		node[idx]->add(s + 1);
	}

	int search(char s[], int d, int ans) {
		if (s[d] == 0) return ans;
		int idx = (s[d] - '0') ^ 1;
		if (node[idx] != nullptr) {
			ans += (1 << (31 - d));
			return node[idx]->search(s, d + 1, ans);
		}
		else {
			return node[idx^1]->search(s, d + 1, ans);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char s[33];
	s[32] = 0;
	int N, ans = 0;
	cin >> N;
	trie* root = new trie();

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		for (int j = 31; j >= 0; --j) {
			if ((temp & 1) == 1) s[j] = '1';
			else s[j] = '0';
			temp >>= 1;
		}
		root->add(s);
		ans = max(ans, root->search(s, 0, 0));
	}
	cout << ans;

	delete root;
	return 0;
}