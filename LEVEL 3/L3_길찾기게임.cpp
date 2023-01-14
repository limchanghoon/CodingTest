#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Node {
public:
    int x, y;
    int number;
    Node* left;
    Node* right;
    Node* parent;
    Node(int _x, int _y, int _number) {
        x = _x;
        y = _y;
        number = _number;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

bool cmp(Node a, Node b) {
    if (a.y == b.y) {
        return a.x > b.x;
    }
    else {
        return a.y > b.y;
    }
}

void addNode(Node* root, Node* newNode) {
    if (newNode->x < root->x) {
        if (root->left == nullptr)
            root->left = newNode;
        else
            addNode(root->left, newNode);
    }
    else {
        if (root->right == nullptr)
            root->right = newNode;
        else
            addNode(root->right, newNode);
    }
}

void postorder(Node* node, vector<int>& answer) {
    if (node->left != nullptr)
        postorder(node->left, answer);
    if (node->right != nullptr)
        postorder(node->right, answer);

    answer.push_back(node->number);

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<Node> nodeV;
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeV.push_back(Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }
    sort(nodeV.begin(),nodeV.end(),cmp);
    for (int i = 1; i < nodeV.size(); i++) {
        addNode(&nodeV[0],&nodeV[i]);
    }

    // 전위 순회
    vector<Node> stack;
    stack.push_back(nodeV[0]);
    while (!stack.empty()) {
        Node n = stack.back();
        stack.pop_back();
        answer[0].push_back(n.number);
        if (n.right != nullptr)
            stack.push_back(*n.right);
        if (n.left != nullptr)
            stack.push_back(*n.left);
    }

    // 후위 순회
    postorder(&nodeV[0], answer[1]);
    return answer;
}

int main() {
    vector<vector<int>> v = solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
    printf("전위 순회\n");
    for (int pre : v[0]) {
        printf("%d, ", pre);
    }
    printf("\n후위 순회\n");
    for (int pre : v[1]) {
        printf("%d, ", pre);
    }
    printf("\n\n");
    return 0;

}