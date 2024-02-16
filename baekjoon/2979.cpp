#include <iostream>

using namespace std;

int main()
{
	int result = 0;
	int prices[4] = { 0, };
	cin >> prices[1] >> prices[2] >> prices[3];
	prices[2] *= 2;	// 1대당 가격이기 때문에 2개 가격은 *2
	prices[3] *= 3; // 1대당 가격이기 때문에 3eo 가격은 *3
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