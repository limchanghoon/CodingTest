#include <iostream>
#include <string>

using namespace std;

/*
1.����(a,e,i,o,u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�.
2.������ 3�� Ȥ�� ������ 3�� �������� ���� �� �ȴ�.
3.���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee �� oo�� ����Ѵ�.
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
		// ��Ģ1,2 //
		if (check_aeiou(s[i])) {
			aeiou = true;
			++aeiou_count;
			bcd_count = 0;
		}
		else {
			aeiou_count = 0;
			++bcd_count;
		}

		// ��Ģ2 //
		if (aeiou_count == 3 || bcd_count == 3)
			return false;

		// ��Ģ3 //
		if (i != 0 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o')
			return false;
	}
	// ��Ģ1
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