#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(const string& a, const string& b) {
		if (a.size() != b.size())
			return a.size() > b.size();
		if (a.compare(b) > 0)
			return true;
		else
			return false;
	}
};

bool isNum(char c) {
	if (c < '0' || c >'9')
		return false;
	return true;
}

string removeZero(string s) {
	int i = 0;
	for (; i < s.size()-1; ++i)
		if (s[i] != '0')
			break;
	return s.substr(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<string,vector<string>,cmp> pq;
	int N;
	cin >> N;
	while(N--) {
		string s, temp = "";
		cin >> s;
		for (int i = 0; i < s.size(); ++i) {
			if (isNum(s[i]))
				temp += s[i];
			else if(temp != "") {
				pq.push(removeZero(temp));
				temp = "";
			}
		}
		if (temp != "")
			pq.push(removeZero(temp));
	}

	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}