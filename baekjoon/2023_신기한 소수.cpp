#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n==0 || n == 1)
		return false;

	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0)
			return false;

	return true;
}

void DFS(int num, int N)
{
	if (!isPrime(num))
		return;
	--N;
	if (N == 0) {
		cout << num << endl;
		return;
	}
	num *= 10;
	for (int i = 1; i < 10; ++i)
	{
		num += i;
		DFS(num, N);
		num -= i;
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i < 10; ++i)
		DFS(i, N);

	return 0;
}