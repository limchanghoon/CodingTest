#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    int min = 100001;
    vector<int> answer;
    map<string, int> gemMap;

    for (int i = 0; i < gems.size(); i++) {
        gemMap.insert({ gems[i], gemMap.size()});
    }

    bool* check = new bool[gemMap.size()];
    int checkCount = 0;
    bool checkAll = false;
    for (int i = 0; i < gemMap.size(); i++) {
        check[i] = false;
    }

    int* gemIdx = new int[gemMap.size()];

    string startGem = gems[0];
    int startIdx = 100001;
    for (int i = 0; i < gems.size(); i++) {
        gemIdx[gemMap[gems[i]]] = i;
        if (!check[gemMap[gems[i]]]) {
            check[gemMap[gems[i]]] = true;
            checkCount++;
            if (checkCount == gemMap.size()) {
                checkAll = true;
                for (int k = 0; k < gemMap.size(); k++) {
                    if (startIdx > gemIdx[k]) {
                        startIdx = gemIdx[k];
                        startGem = gems[gemIdx[k]];
                    }
                }
            }
        }

        if (checkAll) {
            if (startGem == gems[i]) {
                startIdx = i;
                for (int j = 0; j < gemMap.size(); j++) {
                    if (startIdx > gemIdx[j]) {
                        startIdx = gemIdx[j];
                        startGem = gems[gemIdx[j]];
                    }
                }
            }
            if (min > i - startIdx) {
                min = i - startIdx;
                answer.clear();
                answer.push_back(startIdx + 1);
                answer.push_back(i + 1);
            }
        }
    }

    return answer;
}

/*
int main() {
    
    vector<string> input;
    input.push_back("DIA");
    input.push_back("RUBY");
    input.push_back("RUBY");
    input.push_back("DIA");
    input.push_back("DIA");
    input.push_back("EMERALD");
    input.push_back("SAPPHIRE");
    input.push_back("DIA");
    vector<int> v = solution(input);

    printf("%d , %d \n", v[0], v[1]);
    return 0;
}

*/