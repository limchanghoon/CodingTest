#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0, start = 0;
	bool minus = false;
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '+' || s[i] == '-') {
			if (minus)
				sum -= stoi(s.substr(start, i - start));
			else
				sum += stoi(s.substr(start, i - start));
			start = i + 1;
			if (s[i] == '-')
				minus = true;
		}
		else if (i == s.size() - 1) {
			if (minus)
				sum -= stoi(s.substr(start));
			else
				sum += stoi(s.substr(start));
		}
	}
	cout << sum;
	return 0;
}