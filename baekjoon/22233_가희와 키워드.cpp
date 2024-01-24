#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	unordered_set<string> keyword;
	string str;
	while(N--)
	{
		cin >> str;
		keyword.insert(str);
	}

	while(M--)
	{
		cin >> str;
		int cur = 0;
		while (true)
		{
			auto next = str.find(',', cur);
			if (next == str.npos)
			{
				string temp = str.substr(cur);
				if (keyword.find(temp) != keyword.cend())
					keyword.erase(temp);
				break;
			}
			else {
				string temp = str.substr(cur, next - cur);
				if (keyword.find(temp) != keyword.cend())
					keyword.erase(temp);
				cur = next + 1;
			}
		}
		cout << keyword.size() << "\n";
	}
	
	return 0;
}