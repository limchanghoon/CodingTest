#include <iostream>

using namespace std;

#define MOD 10007;

int main()
{
	int table[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = j + 1; k < 10; ++k)
				table[j] = (table[j] + table[k])%MOD;
		
	cout << table[0];
	return 0;
}