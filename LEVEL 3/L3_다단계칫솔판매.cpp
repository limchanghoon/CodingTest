#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void collect_money(map<string, pair<int, string>>& m, const string& seller, int amount) {
    int payment = amount * 0.1f;
    amount -= payment;
    m[seller].first += amount;
    if(payment > 0)
        collect_money(m,m[seller].second, payment);
    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, pair<int, string>> m;
    m.insert({ "-", { 0," " } });
    for (const string& name : enroll) {
        m.insert({ name, {0,""} });
    }
    for (size_t i = 0; i < referral.size(); i++) {
        m[enroll[i]] = { 0, referral[i] };
    }
    for (size_t i = 0; i < seller.size(); i++) {
        collect_money(m, seller[i], 100*amount[i]);
    }
    for (const string& name : enroll) {
        answer.push_back(m[name].first);
    }
    return answer;
}

int main() {
    vector<string>  enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string>  referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string>  seller = { "young", "john", "tod", "emily", "mary" };
    vector<int>  amount = { 12, 4, 2, 5, 10 };

    for (auto n : solution(enroll, referral, seller, amount)) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}