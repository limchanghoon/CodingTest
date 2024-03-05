#include <iostream>
#include <cstring>

using namespace std;

int N;

char table[26][2];

void preorder(char cur) {
	cout << cur;
	if (table[cur - 'A'][0] != '.')
		preorder(table[cur - 'A'][0]);
	if (table[cur - 'A'][1] != '.')
		preorder(table[cur - 'A'][1]);
}

void inorder(char cur) {
	if (table[cur - 'A'][0] != '.')
		inorder(table[cur - 'A'][0]);
	cout << cur;
	if (table[cur - 'A'][1] != '.')
		inorder(table[cur - 'A'][1]);
}

void postorder(char cur) {
	if (table[cur - 'A'][0] != '.')
		postorder(table[cur - 'A'][0]);
	if (table[cur - 'A'][1] != '.')
		postorder(table[cur - 'A'][1]);
	cout << cur;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(table, '.', sizeof(table));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		table[a - 'A'][0] = b;
		table[a - 'A'][1] = c;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}