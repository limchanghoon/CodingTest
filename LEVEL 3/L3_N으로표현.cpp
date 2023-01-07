#include <string>
#include <vector>
#include <set>

using namespace std;

// 배열에 저장하지 않고 한번 연산의 결과값을 재귀적으로 호출해 풀이할 수도 있다. //
int solution(int N, int number) {
	vector<set<int>> v(9);
	int answer = 0;
	for (int i = 1; i < 9; i++) {

		// 0. NN => NNN
		int nn = 0;
		for (int j = 0; j < i; j++) {
			nn *= 10;
			nn += N;
		}
		v[i].insert(nn);

		for (int j = 1; j < i; j++) {
			for (auto itr = v[j].begin(); itr != v[j].end(); itr++) {
				for (auto itr2 = v[i - j].begin(); itr2 != v[i - j].end(); itr2++) {
					// 1.더하기
					if (*itr + *itr2 >= 1)
						v[i].insert(*itr + *itr2);
					// 2. 빼기
					if (*itr - *itr2 >= 1)
						v[i].insert(*itr - *itr2);
					//3. 곱하기
					if (*itr * *itr2 >= 1)
						v[i].insert(*itr * *itr2);
					//4. 나누기
					if (*itr / *itr2 >= 1)
						v[i].insert(*itr / *itr2);
				}
			}
		}
		for (int j = 1; j <= i; j++) {
			if (v[j].find(number) != v[j].end()) {
				return j;
			}
		}

	}
	return -1;

}

/*
int main() {

	// 테스트 케이스 //
	printf("%d\n", solution(8, 53));
	return 0;
}
*/