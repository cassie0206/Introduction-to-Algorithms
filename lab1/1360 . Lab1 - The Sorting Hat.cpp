#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class object {
public:
	string name;
	//long long int g, h, r, s;
	long long int score[4];
	long long int college[4];
	long long int belonging;
	int key;
	//vector<pair<int, string>> belonging;
	//priority_queue<pair<int, char>> q;
};

bool cmp0(object a,object b) { 
	//cout << a.score[a.college[0]];
	if (a.score[a.college[0]] != b.score[b.college[0]]) {
		return a.score[a.college[0]] > b.score[b.college[0]];
	}
	else if (a.score[a.college[1]] != b.score[b.college[1]]) {
		return a.score[a.college[1]] > b.score[b.college[1]];
	}
	else if (a.score[a.college[2]] != b.score[b.college[2]]) {
		return a.score[a.college[2]] > b.score[b.college[2]];
	}
	else if (a.score[a.college[3]] != b.score[b.college[3]]) {
		return a.score[a.college[3]] > b.score[b.college[3]];
	}
	else {
		return a.name < b.name;
	}			
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	long long int n;
	cin >> n;
	int a[16];
	char c;
	for (int i = 0; i < 16; i++) {
		cin >> c;
		switch (c) {
		case 'G':a[i] = 0; break;
		case 'H':a[i] = 1; break;
		case 'R':a[i] = 2; break;
		case 'S':a[i] = 3; break;
		}
	}
	/*for (int i = 0; i < 16; i++) {
		cout << a[i] << endl;
	}*/

	vector<object> v_g, v_h, v_r, v_s;
	object o_student;
	long long int g, h, r, s;
	for (int i = 0; i < n; i++) {
		cin >> o_student.name >> o_student.score[0]; o_student.belonging = o_student.score[0]; o_student.key = 0;
		cin >> o_student.score[1];
		if (o_student.belonging < o_student.score[1]) { o_student.belonging = o_student.score[1]; o_student.key = 1;
		}
		cin >> o_student.score[2];
		if (o_student.belonging < o_student.score[2]) { o_student.belonging = o_student.score[2]; o_student.key = 2;
		}
		cin >> o_student.score[3];
		if (o_student.belonging < o_student.score[3]) { o_student.belonging = o_student.score[3]; o_student.key = 3;
		}
		/*for (int i = 0; i < 4; i++) {
			cout << o_student.score[i].first << " " << o_student.score[i] .second<< endl;
		}*/
		//o_student.belonging.push_back(m_college[o_student.score[4].second]);
		switch (o_student.key) {
		case 0:
			for (int i = 0; i < 4; i++) {
				o_student.college[i] = a[i];
			}
			v_g.push_back(o_student);
			break;
		case 1:
			for (int i = 0; i < 4; i++) {
				o_student.college[i] = a[i+4];
			}
			v_h.push_back(o_student);
			break;
		case 2:
			for (int i = 0; i < 4; i++) {
				o_student.college[i] = a[i+8];
			}
			v_r.push_back(o_student);
			break;
		case 3:
			for (int i = 0; i < 4; i++) {
				o_student.college[i] = a[i+12];
			}
			v_s.push_back(o_student);
			break;
		}
	}
	/*cout << "GRYFFINDOR:";
	for (int i = 0; i < v_g.size(); i++) {
		cout << v_g[i].name << " " << v_g[i].score[0] << " " << v_g[i].score[1] << " " << v_g[i].score[2] << " " << v_g[i].score[3] << " " << v_g[i].college[0] << " " << v_g[i].college[1] << " " << v_g[i].college[2] << " " << v_g[i].college[3] << "\n";
	}cout << "\n";
	
	cout << "HUFFLEPUFF:";
	for (int i = 0; i < v_h.size(); i++) {
		cout << v_h[i].name << "\n";
	}cout << "\n";
	cout << "RAVENCLAW:";
	for (int i = 0; i < v_r.size(); i++) {
		cout << v_r[i].name << "\n";
	}cout << "\n";
	cout << "SLYTHERIN:";
	for (int i = 0; i < v_s.size(); i++) {
		cout << v_s[i].name << "\n";
	}*/
	std::cout << "GRYFFINDOR:";
	if (v_g.empty()) { std::cout << " NO NEW STUDENTS\n"; }
	else {
		std::cout << "\n";
		sort(v_g.begin(), v_g.end(), cmp0);
		for (int i = 0; i < v_g.size(); i++) {
			std::cout << v_g[i].name << "\n";
		}
	}
	std::cout << "HUFFLEPUFF:";
	if (v_h.empty()) { std::cout << " NO NEW STUDENTS\n"; }
	else {
		std::cout << "\n";
		sort(v_h.begin(), v_h.end(), cmp0);
		for (int i = 0; i < v_h.size(); i++) {
			std::cout << v_h[i].name << "\n";
		}
	}
	std::cout << "RAVENCLAW:";
	if (v_r.empty()) { std::cout << " NO NEW STUDENTS\n"; }
	else {
		std::cout << "\n";
		sort(v_r.begin(), v_r.end(), cmp0);
		for (int i = 0; i < v_r.size(); i++) {
			std::cout << v_r[i].name << "\n";
		}
	}
	std::cout << "SLYTHERIN:";
	if (v_s.empty()) { std::cout << " NO NEW STUDENTS\n"; }
	else {
		std::cout << "\n";
		sort(v_s.begin(), v_s.end(), cmp0);
		for (int i = 0; i < v_s.size(); i++) {
			std::cout << v_s[i].name << "\n";
		}
	}

	return 0;
}