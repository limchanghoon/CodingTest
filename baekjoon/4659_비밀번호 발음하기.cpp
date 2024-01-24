#include <iostream>
#include <string>

using namespace std;

/*
1.모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
2.모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
3.같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
*/

bool check_aeiou(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

bool checkPassword(string& s)
{
	bool aeiou = false;
	int aeiou_count = 0;
	int bcd_count = 0;

	for (int i =0 ; i < s.size(); ++i)
	{
		// 규칙1,2 //
		if (check_aeiou(s[i])) {
			aeiou = true;
			++aeiou_count;
			bcd_count = 0;
		}
		else {
			aeiou_count = 0;
			++bcd_count;
		}

		// 규칙2 //
		if (aeiou_count == 3 || bcd_count == 3)
			return false;

		// 규칙3 //
		if (i != 0 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o')
			return false;
	}
	// 규칙1
	if (aeiou)
		return true;
	return false;
}

int main()
{
	while (true)
	{
		string s;
		cin >> s;
		if (s == "end")
			break;
		if(checkPassword(s))
			cout << "<" << s << "> is acceptable." << endl;
		else
			cout << "<" << s << "> is not acceptable." << endl;
	}
	return 0;
}