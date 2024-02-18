#include <iostream>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	float sum = 0;
	int count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '+') {
			sum += 0.5;
		}
		else if(str[i] == 'F') {
			++count;
		}
		else {
			int temp = str[i] - 'A';
			sum += 4 - temp;
			++count;
		}
	}

	cout << fixed;
	cout.precision(5);
	cout << sum/count;
	return 0;
}