#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] == ' ') {
			cout << " ";
			continue;
		}
		int temp = str1[i] - (str2[i % str2.length()] - 'a' + 1);
		if (temp < 'a') temp += 'z' - 'a' + 1;
		cout << (char)(temp);
	}
	return 0;
}