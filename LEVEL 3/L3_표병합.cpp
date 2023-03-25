#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <queue>

using namespace std;

const int X = 50;
const int Y = 50;

string table[X*Y];
int parent[X*Y];
queue<string> q;

void Execute(vector<string>& answer) {
    string type = q.front();
    q.pop();
    if (type == "UPDATE") {
        if (q.size() == 2) {
            string value1 = q.front();
            q.pop();
            string value2 = q.front();
            q.pop();
            for (int i = 0; i < X*Y; i++) {
                if (table[i] == value1)
                    table[i] = value2;
            }
        }
        else if(q.size() == 3) {
            int r = stoi(q.front()) - 1;
            q.pop();
            int c = stoi(q.front()) - 1;
            q.pop();
            string value = q.front();
            q.pop();
            int index = Y * r + c;
            table[index] = value;
            for (int i = 0; i < X * Y; i++) {
                if (parent[i] == parent[index]) {
                    table[i] = value;
                }
            }
        }
    }
    else if (type == "MERGE") {
        int r1 = stoi(q.front()) - 1;
        q.pop();
        int c1 = stoi(q.front()) - 1;
        q.pop();
        int r2 = stoi(q.front()) - 1;
        q.pop();
        int c2 = stoi(q.front()) - 1;
        q.pop();
        int index1 = Y * r1 + c1;
        int index2 = Y * r2 + c2;
        int oldParent1 = parent[index1];
        int oldParent2 = parent[index2];
        if (oldParent1 == oldParent2)
            return;

        if (table[oldParent1] == "")
            table[oldParent1] = table[oldParent2];
        else
            table[oldParent2] = table[oldParent1];

        for (int i = 0; i < X * Y; i++) {
            if (parent[i] == oldParent1 || parent[i] == oldParent2) {
                parent[i] = oldParent1;
                table[i] = table[oldParent1];
            }
        }

    }
    else if (type == "UNMERGE") {
        int r = stoi(q.front()) - 1;
        q.pop();
        int c = stoi(q.front()) - 1;
        q.pop();
        int index = Y * r + c;
        int oldParent = parent[index];
        string s = table[index];

        for (int i = 0; i < X * Y; i++) {
            if (parent[i] == oldParent) {
                parent[i] = i;
                table[i] = "";
            }
        }
        table[index] = s;
    }
    else if (type == "PRINT") {
        int r = stoi(q.front()) - 1;
        q.pop();
        int c = stoi(q.front()) - 1;
        q.pop();
        int index = Y * r + c;
        if (table[index] == "") {
            answer.push_back("EMPTY");
        }
        else {
            answer.push_back(table[index]);
        }

    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    regex r("\\w+");
    smatch match;

    for (int i = 0; i < X * Y; i++) {
        parent[i] = i;
    }

    for (size_t i = 0; i < commands.size(); i++) {
        auto start = sregex_iterator(commands[i].begin(), commands[i].end(), r);
        auto end = sregex_iterator();
        while (start != end) {
            q.push(start->str());
            start++;

        }
        Execute(answer);
    }
    return answer;
}

int main() {
    
    vector<string> v2 = solution(
        { "UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d",
        "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1",
        "UNMERGE 2 2", "PRINT 1 1" });

    for (string& s : v2) {
        cout << s << ", ";
    }
    cout << endl;
    

    return 0;
}