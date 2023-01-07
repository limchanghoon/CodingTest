#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp_si(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool cmp_ii(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, map<int, int>> pqm;
    map<string, int> gen_sum;

    for (int i = 0; i < plays.size(); i++) {
        if (pqm.find(genres[i]) == pqm.end()) {
            map<int, int> pm;
            pqm.insert({ genres[i], pm });
            gen_sum.insert({ genres[i], 0 });
        }
        pqm[genres[i]].insert({ i, plays[i] });
        gen_sum[genres[i]] += plays[i];
    }

    vector<pair<string, int>> vec(gen_sum.begin(), gen_sum.end());

    sort(vec.begin(), vec.end(), cmp_si);
    for (int i = 0; i < vec.size(); i++) {
        vector<pair<int, int>> idxVec(pqm[vec[i].first].begin(), pqm[vec[i].first].end());
        sort(idxVec.begin(), idxVec.end(), cmp_ii);
        answer.push_back(idxVec[0].first);
        if(idxVec.size() > 1)
            answer.push_back(idxVec[1].first);
    }

    return answer;
}

/*
int main() {
    vector<string> gv;
    vector<int> pv;

    gv.push_back("classic");
    gv.push_back("pop");
    gv.push_back("classic");
    gv.push_back("classic");
    gv.push_back("pop");

    pv.push_back(500);
    pv.push_back(600);
    pv.push_back(150);
    pv.push_back(800);
    pv.push_back(2500);

    vector<int> result = solution(gv, pv);

    for (int i = 0; i < result.size(); i++) {
        printf("%d, ",result[i]);
    }

    printf("\n");
    return 0;
}

*/