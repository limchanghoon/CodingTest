#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string minValue, maxValue, sign, sequence;

bool isValid(int depth) {
	if (depth == 0)
		return true;
	//중복검사
	for (int i = 0; i < depth; ++i)
		if (sequence[i] == sequence[depth])
			return false;

	//부등호 검사
	if (sign[depth - 1] == '>')
		if (sequence[depth - 1] <= sequence[depth])
			return false;
	
	if (sign[depth - 1] == '<')
		if (sequence[depth - 1] >= sequence[depth])
			return false;
	
	return true;
}

void permutation(int depth) {
	if (depth == sequence.size()) {
		if (minValue.empty() || minValue > sequence)
			minValue = sequence;
		if (maxValue.empty() || maxValue < sequence)
			maxValue = sequence;
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if (sequence[depth] == ' ') {
			sequence[depth] = i + '0';
			if (isValid(depth))
				permutation(depth + 1);
			sequence[depth] = ' ';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k;
	cin >> k;
	sequence.resize(k+1, ' ');
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		sign += c;
	}
	permutation(0);

	cout << setw(static_cast<streamsize>(k) + 1) << setfill('0') << maxValue << "\n" << setw(static_cast<streamsize>(k) + 1) << setfill('0') << minValue;
	return 0;
}