#include <iostream>
#include <string>
#include <tuple>

using namespace std;

pair<int, int> getSB(int i, int num) {
	string curNumStr = to_string(i);
	string numStr = to_string(num);
	int ss = 0, bb = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (curNumStr[i] == numStr[j]) {
				if (i == j)
					++ss;
				else
					++bb;
			}
	return { ss,bb };
}

void removeCase(bool table[], int num, int s, int b) {
	for (int i = 0; i < 1000; ++i) {
		if (table[i])
			continue;
		int ss, bb;
		tie(ss, bb) = getSB(i, num);
		if (ss != s || bb != b)
			table[i] = true;
	}
}

bool preprocess(int i) {
	string num = to_string(i);
	if (num.size() != 3)					// 3자리 체크
		return true;
	if (num[1] == '0' || num[2] == '0')		// 0체크
		return true;
	if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) // 중복된 숫자 체크
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool table[1000];
	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < 1000; ++i)	// 0 포함된 것 제거, 중복된 숫자 제거
		table[i] = preprocess(i);
	
	for (int i = 0; i < N; ++i) {	// 불가능 케이스 제거
		int num, s, b;
		cin >> num >> s >> b;
		removeCase(table, num, s, b);
	}

	for (int i = 0; i < 1000; ++i)	// 불가능의 여집합 갯수 구하기
		if (!table[i])
			++ans;

	cout << ans;
	return 0;
}