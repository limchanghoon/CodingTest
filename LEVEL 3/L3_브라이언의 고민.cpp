#include <string>
#include <vector>

using namespace std;


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {
	string answer = "";
	vector<char> v;

	bool word = false;
	int wordCnt = 0;
	// case1 ���̿� AaAaA, case2 ���� aAAa
	// �̸� ���� ���� Ȯ��
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == ' ')
			return "invalid";
		if (i < sentence.size() - 1 && 'a' <= sentence[i] && sentence[i] <= 'z' && sentence[i] == sentence[i + 1])
			return "invalid";
	}
	for (int i = 0; i < sentence.size(); i++) {
		char sign = sentence[i];
		if ('A' <= sentence[i] && sentence[i] <= 'Z') {
			// �빮�� �Է�
			answer += sentence[i];
			word = true;
			wordCnt++;
		}
		else {
			// �ҹ��� �Է�
			sign = sentence[i];
			bool isCase1 = false;
			if (word) {
				// (WORD)  AaAaAaA	: case1 ���ɿ��� Ȯ��
				int secondSignIndex = -1;
				for (int j = 0; j < v.size(); j++) {
					if (v[j] == sign)
						return "invalid";
				}

				for (int j = sentence.size() - 1; j >= i; j--) {
					if (sign == sentence[j]) {
						secondSignIndex = j;
						break;
					}
				}

				if ((secondSignIndex - i) % 2 == 0) {
					isCase1 = true;
					int cnt = 0;
					for (int j = i; j <= secondSignIndex; j += 2) {
						if (sign != sentence[j]) {
							isCase1 = false;
							break;
						}
						else {
							cnt++;
						}
					}

					// AaAaA ��� A aAa A�� �켱���� �����Ѵ�.
					if (cnt == 2) {
						isCase1 = false;
					}
				}

				if (isCase1) {
					if (wordCnt > 1) {
						answer.pop_back();
						answer += ' ';
						answer += sentence[i - 1];
					}
					if ('a' <= sentence[i - 1] && sentence[i - 1] <= 'z') {
						return "invalid";
					}
					for (int j = i + 1; j < secondSignIndex + 2; j += 2) {
						if ('A' <= sentence[j] && sentence[j] <= 'Z') {
							answer += sentence[j];
						}
						else {
							return "invalid";
						}
					}
					answer += ' ';
					v.push_back(sign);
					i = secondSignIndex + 1;
					wordCnt = 0;
					word = false;
				}
				
			}

			// Case2 �Ǵ� Case2 �ȿ� Case1�� ���Ե� ��찡 �����ϴ�.
			if(!isCase1) {
				if (word) {
					answer += ' ';
					wordCnt = 0;
					word = false;
				}
				// ������ (aAAAa �Ǵ� aAbAbAa)
				sign = sentence[i];
				int secondSignIndex = -1;
				for (int j = 0; j < v.size(); j++) {
					if (v[j] == sign)
						return "invalid";
				}
				char case1Sign = ' ';
				for (int j = i + 1; j < sentence.size(); j++) {
					if ('a' <= sentence[j] && sentence[j] <= 'z') {
						if (sign == sentence[j]) {
							secondSignIndex = j;
							break;
						}
						else if(case1Sign == ' ') {
							case1Sign = sentence[j];
						}
						else if (case1Sign == sentence[j]) {
							// Case2 ������ Case1�̴�.
						}
						else {
							return "invalid";
						}
					}
				}
				
				if (secondSignIndex == -1) {
					// �ҹ��ڰ� �ϳ��� ���
					return "invalid";
				}
				else if (case1Sign == ' ') {
					// Case2 ���ο� �빮�ڸ� �����ϴ� ���
					for (int j = i + 1; j < secondSignIndex; j++) {
						answer += sentence[j];
					}
					answer += ' ';
					v.push_back(sign);
					i = secondSignIndex;
				}
				else {
					// Case2 ���ο� Case1�� �����ϴ� ���
					for (int j = i + 2; j <= secondSignIndex - 2; j += 2) {
						if(case1Sign != sentence[j])
							return "invalid";
					}
					for (int j = i + 1; j < secondSignIndex; j += 2) {
						if ('a' <= sentence[j] && sentence[j] <= 'z')
							return "invalid";
						answer += sentence[j];
					}
					answer += ' ';
					v.push_back(sign);
					v.push_back(case1Sign);
					i = secondSignIndex;
				}
			}
		}
	}
	if(answer[answer.size()-1] == ' ')
		answer.pop_back();
	return answer;
}

/*
int main() {

	printf("%s\n", solution("TxTxTxbAb").c_str());
	return 0;
}
*/