#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solve(const string& str)
{
    int result = 0;

    stack<char> stk;
    int temp = 1;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            temp *= 2;
            stk.push('(');
        }
        else if (str[i] == '[')
        {
            temp *= 3;
            stk.push('[');
        }
        else if (str[i] == ')')
        {
            if (stk.empty() || stk.top() != '(')
                return 0;
            
            if (str[i - 1] == '(')
                result += temp;
            temp /= 2;
            stk.pop();
        }
        else if (str[i] == ']')
        {
            if (stk.empty() || stk.top() != '[') 
                return 0;

            if (str[i - 1] == '[')
                result += temp;
            temp /= 3;
            stk.pop();
        }
    }

    if (!stk.empty()) return 0;

    return result;
}

int main()
{
    string str;
    cin >> str;

    cout << solve(str) << endl;

    return 0;
}