#include <iostream>
#include <algorithm>

using namespace std;

bool permutation(int* heights, bool* visited, int cnt, int sum)
{
	if (cnt == 7)
	{
		if (sum == 100)
			return true;
		return false;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			if (permutation(heights, visited, cnt + 1, sum + heights[i]))
				return true;
			visited[i] = false;
		}
	}
	return false;
}

int main()
{
	int heights[9];
	bool visited[9];
	for (int i = 0; i < 9; ++i) {
		cin >> heights[i];
		visited[i] = false;
	}
	sort(heights, heights + 9);
	permutation(heights, visited, 0, 0);
	for (int i = 0; i < 9; ++i)
	{
		if (visited[i])
			cout << heights[i] << endl;
	}
	return 0;
}