#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;
bool visited[8];
int intputTable[8];
int currentTable[8];

int generate(int depth) {
	int result = 0;
	if (++depth == n)
	{
		int sum = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			sum += abs(currentTable[i] - currentTable[i + 1]);
		}
		return sum;
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		currentTable[depth] = intputTable[i];
		result = max(result, generate(depth));
		visited[i] = false;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> intputTable[i];
	}
	cout<<generate(-1);
	return 0;
}