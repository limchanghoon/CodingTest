#include <iostream>

using namespace std;

int main()
{
	int result = 0;
	int prices[4] = { 0, };
	cin >> prices[1] >> prices[2] >> prices[3];
	prices[2] *= 2;	// 1��� �����̱� ������ 2�� ������ *2
	prices[3] *= 3; // 1��� �����̱� ������ 3eo ������ *3
	int table[101] = { 0, };
	int inout[3][2] = { {0,0},{0,0},{0,0} };
	for (int i = 0; i < 3; ++i)
		cin >> inout[i][0] >> inout[i][1];

	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j < 3; ++j)
			if (inout[j][0] <= i && i < inout[j][1])
				++table[i];
		result += prices[table[i]];
	}

	cout << result << endl;

	return 0;
}