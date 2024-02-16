#include <iostream>

using namespace std;

int main()
{
	long long S;
	cin >> S;

	long long sum = 0;
	for (long long i = 1; true; ++i)
	{
		sum += i;
		if (sum == S) {
			cout << i << endl;
			break;
		}
		else if (sum > S) {
			cout << i - 1 << endl;
			break;
		}
	}

	return 0;
}