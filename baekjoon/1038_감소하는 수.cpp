#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> descNums;

void generate(long long num)
{
	descNums.push_back(num);

	int last = num % 10;

	for (int i = 0; i < last; ++i)
		generate(num * 10 + i);
}

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < 10; ++i)
		generate(i);

	sort(descNums.begin(), descNums.end());

	if(descNums.size() <= N)
		cout << -1 << endl;
	else
		cout << descNums[N] << endl;

	return 0;
}