#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


void binary_search(vector<pair<int,int>>& v,int key,int s,int e) {
	if (s > e) { cout << "-1\n"; return; }
	if (s == e && v[s].second != key) { cout << "-1\n"; return; }
	int middle = (s + e) / 2;
	if (v[middle].second == key) { cout << v[middle].first << "\n"; return; }
	else if (v[middle].second > key) { binary_search(v, key, s, middle); }
	else{ binary_search(v, key, middle+1, e); }
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int n, m, h, key = 0;
	cin >> n >> m;
	vector<pair<int,int>> s, l;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (i == 0) { l.push_back(pair<int, int>(i, h)); }
		else {
			if (l[i - 1].second >= h) { key = i; s.push_back(pair<int, int>(i, h)); break; }
			else { l.push_back(pair<int, int>(i, h)); }
		}
	}
	for (int i = key + 1; i < n; i++) {
		cin >> h;
		s.push_back(pair<int, int>(i, h));
	}
	reverse(s.begin(), s.end()); s.insert(s.end(), l.begin(), l.end());
	
	for (int i = 0; i < m; i++) {
		cin >> h;
		binary_search(s, h, 0, n-1);
	}


	return 0;
}