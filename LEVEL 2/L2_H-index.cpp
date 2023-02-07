#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++) {
        if (i + 1 <= citations[i]) {
            answer = citations[i];
        }
        else {
            break;
        }
    }
    return answer;
}

int main() {
    printf("%d\n", solution({ 3,0,6,1,5 }));
    return 0;
}