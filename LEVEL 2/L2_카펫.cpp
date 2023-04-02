#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    // x*y = brown + yellow;
    // x>=3 ±×¸®°í y>=3
    int by = brown + yellow;
    for (int y = 3; y <= by; y++) {
        int a = by % y;
        int x = by / y;
        if (a == 0 && 2*(x+y)-4 == brown && (x-2)*(y-2) == yellow) {
            return { x, y };
        }
    }
}


int main() {
    auto v1 = solution(10,2);
    auto v2 = solution(8,1);
    auto v3 = solution(24,24);
    cout << v1[0] << ", " << v1[1] << endl;
    cout << v2[0] << ", " << v2[1] << endl;
    cout << v3[0] << ", " << v3[1] << endl;
    return 0;
}