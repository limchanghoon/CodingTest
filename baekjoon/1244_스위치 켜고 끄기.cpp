#include <iostream>
#include <vector>

using namespace std;

int reverse(int num)
{
	return (num == 1) ? 0 : 1;
}

// 남학생 : 받은 수의 배수를 반전시킴
// 여학생 : 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간 반전시킴
void doIt(int gender, int num, vector<int>& switchs)
{
	if (gender == 1) // 남학생
	{
		for (int i = num; i < switchs.size(); i += num)
			switchs[i] = reverse(switchs[i]);
	}
	else // 여학생
	{
		switchs[num] = reverse(switchs[num]);
		for (int pre = num-1, post = num+1; 0 < pre && post < switchs.size(); --pre, ++post)
		{
			if (switchs[pre] != switchs[post])
				break;
			switchs[pre] = reverse(switchs[pre]);
			switchs[post] = reverse(switchs[post]);
		}
	}
}

int main()
{
	int N, M;
	cin >> N;
	vector<int> switchs(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> switchs[i];
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int gender, num;
		cin >> gender;
		cin >> num;

		doIt(gender, num, switchs);
	}
	
	for (int i =0;i<N;++i)
	{
		if (i != 0 && i % 20 == 0)
			cout << "\n";
		cout << switchs[i+1] << " ";
	}

	return 0;
}