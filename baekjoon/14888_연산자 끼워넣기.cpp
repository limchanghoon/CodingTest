#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void calculate(const vector<int>& A, vector<int>& B, int preResult, int curA, vector<int>& result)
{
    if (curA == A.size())
    {
        result[0] = max(preResult, result[0]);
        result[1] = min(preResult, result[1]);
        return;
    }

    if (B[0] > 0)
    {
        --B[0];
        int newResult = preResult + A[curA];
        calculate(A, B, newResult, curA + 1, result);
        ++B[0];
    }

    if (B[1] > 0)
    {
        --B[1];
        int newResult = preResult - A[curA];
        calculate(A, B, newResult, curA + 1, result);
        ++B[1];
    }

    if (B[2] > 0)
    {
        --B[2];
        int newResult = preResult * A[curA];
        calculate(A, B, newResult, curA + 1, result);
        ++B[2];
    }

    if (B[3] > 0)
    {
        --B[3];
        int newResult = preResult / A[curA];
        calculate(A, B, newResult, curA + 1, result);
        ++B[3];
    }


}


vector<int> solve(const vector<int>& A, vector<int>& B)
{
    int N = A.size();
    vector<int> result = { INT32_MIN, INT32_MAX };

    int tmp = 0;
    calculate(A, B, A[0], 1, result);

    return result;
}

int main()
{
    int n;
    vector<int> a;
    vector<int> b;

    cin >> n;

    do {
        cin >> n;
        a.push_back(n);
    } while (getc(stdin) == ' ');

    do {
        cin >> n;
        b.push_back(n);
    } while (getc(stdin) == ' ');

    auto result = solve(a, b);
    cout << result[0] << endl;
    cout << result[1] << endl;

    return 0;
}