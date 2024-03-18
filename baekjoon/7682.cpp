#include <iostream>
#include <string>

using namespace std;

const int table[8][3] = {
	{0,1,2},{3,4,5},{6,7,8},
	{0,3,6},{1,4,7},{2,5,8},
	{0,4,8},{2,4,6} 
};


bool check(const string& str, char cur) {
	for (int i = 0; i < 8; ++i) {
		if (str[table[i][0]] == cur && str[table[i][1]] == cur && str[table[i][2]] == cur) return true;
	}
	return false;
}

bool solve(const string& str) {
	int X_Cnt = 0;
	int O_Cnt = 0;
	for (int i = 0; i < 9; ++i) {
		if (str[i] == 'X') X_Cnt++;
		else if (str[i] == 'O') O_Cnt++;
	}

	bool X_Win = check(str, 'X');
	bool O_Win = check(str, 'O');

	// F : 동시에 이길 수 없음
	if (X_Win && O_Win) return false;

	// T1 : X가 이겼으면 X == O + 1
	if (X_Win && X_Cnt == O_Cnt + 1) return true;
	// T2 : O가 이겼으면 X == O 
	if (O_Win && X_Cnt == O_Cnt) return true;
	// T3 : 아무도 못 이기고 칸이 꽉차면 끝남
	if (!X_Win && !O_Win && X_Cnt == 5 && O_Cnt == 4) return true;

	// 안끝남 or 불가능한 경우
	return false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		string input;
		cin >> input;
		if (input == "end")	break;
		if (solve(input)) cout << "valid" << endl;
		else cout << "invalid" << endl;
	}
	return 0;
}