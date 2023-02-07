#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuples;

    // int형 벡터로 변환
    for (size_t i = 2; i < s.size()-1;) {
        int start = i;
        int end = s.find("}", i + 1);
        vector<int> tmp;
        while (start < end) {
            int comma;
            if (s.find(",", start) == string::npos || s.find(",", start) > end) {
                comma = end;
            }
            else {
                comma = s.find(",", start);
            }
            tmp.push_back(stoi(s.substr(start, comma - start)));
            start = comma + 1;
        }
        tuples.push_back(tmp);
        i = start+2;
    }

    /* 원소의 개수가 적은 순서가 되도록 정렬
    *  {2}
    *  {2,1}
    *  {1,2,3}
    *  {1,2,4,3}
    */ 
    sort(tuples.begin(), tuples.end(), cmp);

    /*
    * 원소의 개수가 적은 집합부터 시작해서 
    * set에 들어있지 않은 원소를 하나씩 넣는다
    */
    set<int> element_set;
    for (vector<int> v : tuples) {
        for (int n : v) {
            auto iter = element_set.find(n);
            if (iter == element_set.end()) {
                element_set.insert(n);
                answer.push_back(n);
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> v = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    for (int n : v) {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}