#include <iostream>
#include <string>

using namespace std;

int N;

struct MyQueue {
	int table[2000000];
	int _front = 0, _back = -1;

	void push(int num) {
		table[++_back] = num;
	}

	int pop() {
		if (size() == 0)
			return -1;
		return table[_front++];
	}

	int size() {
		return _back - _front + 1;
	}

	int empty() {
		if (size() == 0)
			return 1;
		return 0;
	}

	int front() {
		if (size() == 0)
			return -1;
		return table[_front];
	}

	int back() {
		if (size() == 0)
			return -1;
		return table[_back];
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	MyQueue* myQueue = new MyQueue();

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i) {
		string str;
		getline(cin, str);
		if (str.substr(0, 4) == "push") {
			myQueue->push(stoi(str.substr(5)));
		}
		else if (str.substr(0, 3) == "pop") {
			cout << myQueue->pop() << "\n";
		}
		else if (str.substr(0, 4) == "size") {
			cout << myQueue->size() << "\n";
		}
		else if (str.substr(0, 5) == "empty") {
			cout << myQueue->empty() << "\n";
		}
		else if (str.substr(0, 5) == "front") {
			cout << myQueue->front() << "\n";
		}
		else if (str.substr(0, 4) == "back") {
			cout << myQueue->back() << "\n";
		}
	}
	delete myQueue;

	return 0;
}