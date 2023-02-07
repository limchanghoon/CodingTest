#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for (vector<string> v : clothes) {
        if (m.find(v[1]) != m.end()) {
            ++(m.find(v[1])->second);
        }
        else {
            m.insert({ v[1],1 });
        }
    }
    
    for (auto iter : m) {
        answer *= (iter.second + 1);
    }
    return --answer;
}

int main() {
    printf("%d\n", solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} }));
    return 0;
}