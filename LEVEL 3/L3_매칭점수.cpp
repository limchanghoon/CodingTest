#include <string>
#include <vector>

using namespace std;

size_t nextPos(string str, string word, int startPos) {
    if (str.find(word, startPos) != string::npos) {
        return str.find(word, startPos)+word.size();
    }
    else {
        return string::npos;
    }

}

int solution(string word, vector<string> pages) {
    int answer = 0;
    double* scores = new double[pages.size()]{};
    double* last_scores = new double[pages.size()]{};
    int* link_counts = new int[pages.size()]{};
    vector<vector<int>> links(pages.size(), vector<int>(pages.size(),0));
    string* urls = new string[pages.size()];

    for (int i = 0; i < word.size(); i++) {
        word[i] = toupper(word[i]);
    }

    for (int i = 0; i < pages.size(); i++) {
        // url 찾기
        int x = nextPos(pages[i], "<meta property=\"og:url\" content=\"", 0);
        int y = pages[i].substr(x).find("\"/>");
        urls[i] = pages[i].substr(x, y);
    }

    for (int i = 0; i < pages.size(); i++) {
        // <body> 찾기
        int body = nextPos(pages[i], "<body>", 0);
        int x = body;
        int y = pages[i].find("</body>", x);

        // 링크 찾기
        while (true) {
            if (x >= y || nextPos(pages[i], "<a href=\"", x ) == string::npos)
                break;
            int x2 = nextPos(pages[i], "<a href=\"", x);
            link_counts[i]++;
            int y2 = pages[i].substr(x2).find("\">");
            string tmpURL = pages[i].substr(x2, y2);
            for (int k = 0; k < pages.size(); k++) {
                if (tmpURL.compare(urls[k]) == 0) {
                    links[i][k]++;
                }
            }
            x = x2 + y2;
        }

        // word찾기 대문자로 만들고 비교
        string upper = "";
        for (int k = body; k < y; k++) {
            upper+=toupper(pages[i][k]);
        }
        int cursor = 0;
        while (true) {
            if (nextPos(upper, word, cursor) == string::npos)
                break;
            cursor = nextPos(upper, word, cursor);
            // 다음 문자가 알파벳이 아니면 word 찾은 것이다.
            if (!(upper[cursor] >= 'A' && upper[cursor] <= 'Z')) {
                scores[i]++;
            }
            cursor++;
        }
    }

    // 기본점수 링크 점수 계산해서 결과 고르기
    for (int i = 0; i < pages.size(); i++) {
        for (int k = 0; k < pages.size(); k++) {
            if (link_counts[i] != 0)
                last_scores[k] += (double)scores[i] * (double)links[i][k]/(double)link_counts[i];
        }
        last_scores[i] += scores[i];
    }

    // 최종적으로 가장 큰 점수 고르기
    double max = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (max < last_scores[i]) {
            max = last_scores[i];
            answer = i;
        }
    }
    
    return answer;
}

int main() {
    
    printf("%d\n", solution("blind",
        {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>"
        , "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>"
        , "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
        } ));
    

    printf("%d\n", solution("Muzi",
        { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>"
        ,"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
        }));

    return 0;
}