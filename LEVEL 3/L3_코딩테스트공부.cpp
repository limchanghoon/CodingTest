/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int costs[151][151];

int solution(int alp, int cop, vector<vector<int>> problems) {
	for (int i = 0; i < 151; i++) {
		for (int j = 0; j < 151; j++) {
			costs[i][j] = 333333333;
		}
	}

	// 알고력(코딩력)을 1올리고 1시간 쓰는 경우
	problems.push_back({ 0,0,1,0,1 });
	problems.push_back({ 0,0,0,1,1 });

	// 채워야하는 알고력, 코딩력 계산
	int alp_max = 0, cop_max = 0;
	for (auto temp : problems) {
		if (temp[0] > alp_max) {
			alp_max = temp[0];
		}
		if (temp[1] > cop_max) {
			cop_max = temp[1];
		}
	}

	// 이미 조건이 충족되면 최대 요구력으로 바꿔줘야함
	if(alp > alp_max)
		alp = alp_max;
	if (cop > cop_max)
		cop = cop_max;

	costs[alp][cop] = 0;

	// 루프를 돌며 해당 알고력과 코딩력에 최소의 시간을 저장함;
	for (int i = alp; i <= alp_max; i++) {
		for (int j = cop; j <= cop_max; j++) {
			for (auto temp : problems) {
				if (i >= temp[0] && j >= temp[1]) {
					int x = min(i + temp[2], alp_max);
					int y = min(j + temp[3], cop_max);
					costs[x][y] = min(costs[i][j] + temp[4], costs[x][y]);
				}
			}
		}
	}
	return costs[alp_max][cop_max];

}

int main() {
	//  [alp_req, cop_req, alp_rwd, cop_rwd, cost]
	printf("Result : %d\n", solution(10, 10, { {10,15,2,1,2},{20,20,3,3,4} }));
	return 0;
}
*/