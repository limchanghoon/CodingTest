#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<float> calTime(vector<float> times,float _procesTime) {
	float hh = times[0];
	float mm = times[1];
	float ss = times[2];
	float processTime = _procesTime;
	if (ss - (processTime - 0.001f) < 0) {
		if (mm - 1 < 0) {
			if (hh - 1 < 0) {
				return { 0,0,0 };
			}
			else {
				return { hh - 1,(mm + 60) - 1,(ss + 60) - (processTime - 0.001f) };
			}
		}
		else {
			return { hh , mm - 1,(ss + 60) - (processTime - 0.001f) };
		}
	}
	else {
		return { hh, mm, ss - (processTime - 0.001f) };
	}
}

bool compareTime(vector<float> times, vector<float> comTime) {	// 1번 매개변수가 더 빠르면 True, 같은 경우도 True
	if (times[0] < comTime[0]) {
		return true;
	}
	else if (times[0] > comTime[0]) {
		return false;
	}
	else {
		if (times[1] < comTime[1]) {
			return true;
		}
		else if (times[1] > comTime[1]) {
			return false;
		}
		else {
			if (times[2] < comTime[2]) {
				return true;
			}
			else if (times[2] > comTime[2]) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<vector<float>> sv;
	vector<vector<float>> ev;
	for (int i = 0; i < lines.size(); i++) {
		float hh = stoi(lines[i].substr(11,2));
		float mm = stoi(lines[i].substr(14, 2));
		float ss = stof(lines[i].substr(17, 6));
		float processTime = stof(lines[i].substr(24));
		ev.push_back({ hh,mm,ss });

		sv.push_back(calTime({ hh,mm,ss }, processTime));
		
	}


	for (int i = ev.size() - 1; i >= 0; i--) {
		int count = 0;
		vector<float> tempv = calTime({ ev[i][0],ev[i][1],ev[i][2] }, 1);
		for (int j = ev.size() - 1; j >= 0; j--) {
			if (compareTime(tempv, sv[j]) && compareTime(sv[j], ev[i])) {
				count++;
			}
			else if (compareTime(tempv, ev[j]) && compareTime(ev[j], ev[i])) {
				count++;
			}
			else if (compareTime(sv[j],tempv) && compareTime(ev[i], ev[j])) {
				count++;
			}
		}
		if (count > answer) {
			answer = count;
		}
	}

	for (int i = sv.size() - 1; i >= 0; i--) {
		int count = 0;
		vector<float> tempv = calTime({ sv[i][0],sv[i][1],sv[i][2] }, 1);
		for (int j = sv.size() - 1; j >= 0; j--) {
			if (compareTime(tempv, sv[j]) && compareTime(sv[j],sv[i])) {
				count++;
			}
			else if (compareTime(tempv, ev[j]) && compareTime(ev[j], sv[i])) {
				count++;
			}
			else if (compareTime(sv[j], tempv) && compareTime(ev[i], ev[j])) {
				count++;
			}
		}
		if (count > answer) {
			answer = count;
		}
	}

	return answer;
}



int main() {
	vector<string> v;
	
	// 테스트 케이스
	v.push_back("2016-09-15 20:59:57.421 0.351s");
	v.push_back("2016-09-15 20:59:58.233 1.181s");
	v.push_back("2016-09-15 20:59:58.299 0.8s");
	v.push_back("2016-09-15 20:59:58.688 1.041s");
	v.push_back("2016-09-15 20:59:59.591 1.412s");
	v.push_back("2016-09-15 21:00:00.464 1.466s");
	v.push_back("2016-09-15 21:00:00.741 1.581s");
	v.push_back("2016-09-15 21:00:00.748 2.31s");
	v.push_back("2016-09-15 21:00:00.966 0.381s");
	v.push_back("2016-09-15 21:00:02.066 2.62s");
	v.push_back("2016-09-15 21:00:10.001 3s");
	v.push_back("2016-09-15 21:00:09.001 0.1s");
	//
	
	cout << solution(v) << endl;
	return 0;
}
