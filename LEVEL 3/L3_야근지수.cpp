#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(),works.end(),greater<int>());

    vector<int>::size_type i = 1;
    int standard = 0;
    while (n > 0) {
        if (i >= works.size()) {
            standard = works[works.size() - 1] - 1;
        }
        else {
            standard = works[i];
        }
        bool next = true;
        for (vector<int>::size_type j = 0; j < i; j++) {
            if (works[j] > standard) {
                next = false;
                works[j]--;
                n--;
                if (works[j] < 0)
                    return 0;
            }
            if (n == 0)
                break;
        }
        if (n == 0)
            break;
        if (next)
            i++;
    }

    for (vector<int>::size_type k = 0; k < works.size(); k++) {
        answer += static_cast<long long>(works[k]) * static_cast<long long>(works[k]);
    }


    return answer;
}
/*
int main() {
    printf("%lld", solution(3, { 1,1 }));
    return 0;
}
*/