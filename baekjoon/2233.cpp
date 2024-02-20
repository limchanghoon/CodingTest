#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int N, X, Y;
string binaryNum;
int answer[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cutNum = -1;

	cin >> N;
	cin >> binaryNum;
	cin >> X >> Y;

	int next = 1;
	vector<int> vec(N + 1);
	stack<int> stk;

	// 1. ���� ��� 2�� ���� �и� ���ϱ� 
	for (int i = 0; i < binaryNum.size(); ++i) {
		if (binaryNum[i] == '0') {
			stk.push(next);
			if (i == X - 1) vec[next]++;
			if (i == Y - 1) vec[next]++;
			++next;
		}
		else {
			int temp = stk.top();
			stk.pop();
			if (i == X - 1) vec[temp]++;
			if (i == Y - 1) vec[temp]++;

			if(!stk.empty())
				vec[stk.top()] += vec[temp];
		}
	}

	// 2. ���� ��� 2�� ���� �и��� �ּ� ���ϱ�
	next = 1;
	for (int i = 0; i < binaryNum.size(); ++i) {
		if (binaryNum[i] == '0') {
			if (vec[next] == 2)
				cutNum = next;
			++next;
		}
	}

	// 3. (2.)���� ���� ���� in, out �� ���ϱ�
	next = 1;
	for (int i = 0; i < binaryNum.size(); ++i) {
		if (binaryNum[i] == '0') {
			stk.push(next);
			if (cutNum == next)
				answer[0] = i + 1;
			++next;
		}
		else {
			int temp = stk.top();
			stk.pop();
			if (cutNum == temp)
				answer[1] = i + 1;
		}
	}

	cout << answer[0] << " " << answer[1];
	return 0;
}
