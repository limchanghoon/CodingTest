#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	// ���� ���� ��� ���� �տ� �´�.(������ ���� ���� �տ� �´�.)
	// (double)B/A < (double)D/C   �纯�� A*C�� ���ߴ�.
	if (B * C < D * A) {
		long long temp = A;
		A = C;
		C = temp;

		temp = B;
		B = D;
		D = temp;
	}

	// ������ ���� ���� A, C�� �ּ� ����� �̻� �� ������ ����
	long long ans = numeric_limits<long long>::max();
	for (int i = 0; i < C; ++i) {
		long long cntA = A * i;
		if (N < cntA) {
			long long money = B * i;
			ans = min(ans, money);
			break;
		}

		long long j = (N - cntA) / C + 1;
		if ((N - cntA) % C == 0) j--;

		long long money = B * i + D * j;
		ans = min(ans, money);
	}
	cout << ans;
	return 0;
}