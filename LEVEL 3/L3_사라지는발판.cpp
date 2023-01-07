#include <string>
#include <vector>

using namespace std;

// À§, ¾Æ·¡, ÁÂ, ¿ì
int* r = new int[] { -1, 1, 0, 0 };
int* c = new int[] { 0, 0, -1, 1 };

int turnB(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int count, bool winA);

int turnA(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int count, bool winA) {

    int answer = -1;

    if (winA) {
        if (board[aloc[0]][aloc[1]] == 0)
            return -1;

        count++;
        board[aloc[0]][aloc[1]] = 0;

        for (int i = 0; i < 4; i++) {
            int ar = aloc[0] + r[i];
            int ac = aloc[1] + c[i];
            if (ar >= 0 && ar < board.size() && ac >=0 && ac < board[0].size() && board[ar][ac] != 0) {
                aloc[0] += r[i];
                aloc[1] += c[i];
                int temp = turnB(board, aloc, bloc, count, winA);
                if (temp != -1 && (answer == -1 || answer > temp)) {
                    answer = temp;
                }
                aloc[0] -= r[i];
                aloc[1] -= c[i];
            }
        }

        count--;
        board[aloc[0]][aloc[1]] = 1;

        return answer;
    }
    else {
        if (board[aloc[0]][aloc[1]] == 0)
            return count;

        count++;
        board[aloc[0]][aloc[1]] = 0;

        for (int i = 0; i < 4; i++) {
            int ar = aloc[0] + r[i];
            int ac = aloc[1] + c[i];
            if (ar >= 0 && ar < board.size() && ac >= 0 && ac < board[0].size() && board[ar][ac] != 0) {
                aloc[0] += r[i];
                aloc[1] += c[i];
                int temp = turnB(board, aloc, bloc, count, winA);
                if (temp == -1) {
                    return -1;
                }
                if (answer == -1 || answer < temp) {
                    answer = temp;
                }
                aloc[0] -= r[i];
                aloc[1] -= c[i];
            }
        }

        count--;
        board[aloc[0]][aloc[1]] = 1;

        if (answer == -1) {
            return count;
        }
        else {
            return answer;
        }
    }
}

int turnB(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int count, bool winA) {

    int answer = -1;

    if (winA) {
        if (board[bloc[0]][bloc[1]] == 0)
            return count;

        count++;
        board[bloc[0]][bloc[1]] = 0;

        for (int i = 0; i < 4; i++) {
            int br = bloc[0] + r[i];
            int bc = bloc[1] + c[i];
            if (br >= 0 && br < board.size() && bc >= 0 && bc < board[0].size() && board[br][bc] != 0) {
                bloc[0] += r[i];
                bloc[1] += c[i];
                int temp = turnA(board, aloc, bloc, count, winA);
                if (temp == -1) {
                    return -1;
                }
                if (answer == -1 || answer < temp) {
                    answer = temp;
                }
                bloc[0] -= r[i];
                bloc[1] -= c[i];
            }
        }

        count--;
        board[bloc[0]][bloc[1]] = 1;

        if (answer == -1) {
            return count;
        }
        else {
            return answer;
        }
    }
    else {
        if (board[bloc[0]][bloc[1]] == 0)
            return -1;

        count++;
        board[bloc[0]][bloc[1]] = 0;

        for (int i = 0; i < 4; i++) {
            int br = bloc[0] + r[i];
            int bc = bloc[1] + c[i];
            if (br >= 0 && br < board.size() && bc >= 0 && bc < board[0].size() && board[br][bc] != 0) {
                bloc[0] += r[i];
                bloc[1] += c[i];
                int temp = turnA(board, aloc, bloc, count, winA);
                if (temp != -1 && (answer == -1 || answer > temp)) {
                    answer = temp;
                }
                bloc[0] -= r[i];
                bloc[1] -= c[i];
            }
        }

        count--;
        board[bloc[0]][bloc[1]] = 1;

        return answer;
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;

    int result1 = turnA(board, aloc, bloc, 0, true);
    int result2 = turnA(board, aloc, bloc, 0, false);

    if (result1 == -1) {
        answer = result2;
    }
    else if (result2 == -1) {
        answer = result1;
    }
    else {
        printf("BUG!! result1 : %d, result2 : %d\n", result1, result2);
    }

    return answer;
}

/*
int main() {
    //vector<vector<int>> v = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    //vector<int> v1 = { 1, 0 };
    //vector<int> v2 = { 1, 2 };

    //vector<vector<int>> v = { {1, 1, 1, 0, 1, 1}};
    //vector<int> v1 = { 0, 0 };
    //vector<int> v2 = { 0, 5 };

    vector<vector<int>> v = { {1, 1} };
    vector<int> v1 = { 0, 0 };
    vector<int> v2 = { 0, 1 };

    printf("Result : %d\n", solution(v, v1, v2));
    return 0;
}

*/