#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// 바이너리 형태로 만듦. 10 => "1010"
void toBinary(long long n, string& binary)
{
    if (n / 2 != 0) {
        toBinary(n / 2, binary);
    }
    binary.append(to_string(n % 2));
}

// 1 3 7 15 31 ... (2^n -1 갯수에 맞게 0으로 앞에 채움)
void fill_by_zero(string& binary) {
    for (int i = 1; true; i++) {
        int tmp = pow(2, i) - 1;
        if (binary.size() <= tmp) {
            string zeros(tmp - binary.size(), '0');
            binary.insert(0, zeros);
            break;
        }
    }
}
// 100 0 000 = > 불가능
// 001 1 010 => 불가능
// 000 1 010 => 가능
//   1 0 1   => 불가능 
bool check_tree(const string& binary, size_t bottom, size_t top) {
    // 리프노드 판단
    if (bottom == top) {
        return true;
    }
    size_t mid = (bottom + top) / 2;
    // 0인 노드의 자식이 1이면 불가능한 경우이다.
    if (binary[mid] == '0') {
        if (binary[(bottom + mid - 1) / 2] == '1' || binary[(mid + 1 + top) / 2] == '1') {
            return false;
        }
    }
    if (!check_tree(binary, bottom, mid - 1))
        return false;
    if (!check_tree(binary, mid + 1, top))
        return false;
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long n : numbers) {
        string binary = "";
        toBinary(n, binary);
        fill_by_zero(binary);
        answer.push_back(check_tree(binary, 0, binary.size() - 1));
    }
    return answer;
}


int main() {
    cout << "문제1 정답 : ";
    for (int n : solution({ 7, 42, 5 })) {
        cout << n << " ";
    }
    cout << endl;

    cout << "문제2 정답 : ";
    for (int n : solution({ 63, 111, 95 })) {
        cout << n << " ";
    }
    cout << endl;

    cout << "문제3 정답 : ";
    for (int n : solution({ 5, 10, 26, 64 })) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}