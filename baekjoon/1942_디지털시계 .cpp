#include <iostream>
#include <string>

using namespace std;

int convert(int h,int m,int s)
{
	string strH, strM, strS;
	if (h < 10)
		strH = "0";
	strH += to_string(h);

	if (m < 10)
		strM = "0";
	strM += to_string(m);

	if (s < 10)
		strS = "0";
	strS += to_string(s);

	return stoi(strH + strM + strS);
}

int solve(string start, string end)
{
	int result = 0;
	int h1 = stoi(start.substr(0, 2)), m1 = stoi(start.substr(3, 2)), s1 = stoi(start.substr(6, 2));
	int h2 = stoi(end.substr(0, 2)), m2 = stoi(end.substr(3, 2)), s2 = stoi(end.substr(6, 2));

	if (convert(h1, m1, s1) % 3 == 0)
		++result;

	while (h1 != h2 || m1 != m2 || s1 != s2) {
		if (++s1 == 60) {
			s1 = 0;
			if (++m1 == 60) {
				m1 = 0;
				if (++h1 == 24) {
					h1 = 0;
				}
			}
		}
		if (convert(h1, m1, s1) % 3 == 0)
			++result;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int n = 0; n < 3; ++n)
	{
		string start,end;
		cin >> start >> end;
		cout << solve(start, end) << "\n";
	}
	return 0;
}