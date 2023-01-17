#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
#define int long long

using namespace std;

class disjoint_set {
public:
	vector<int> p, size;
	int n;

	disjoint_set(int n){
		p.resize(n);
		size.resize(n, 0);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}

	void merge(int x, int y) {
		int x_leader = find(x);
		int y_leader = find(y);


		if (x_leader == y_leader) {
			return;
		}
		else {
			if (size[x_leader] >= size[y_leader]) {
				p[y_leader] = x_leader;//本來是他自己 後來變成x_leader
				size[x_leader] += size[y_leader];
			}
			else {
				p[x_leader] = y_leader;//本來是他自己 後來變成y_leader
				size[y_leader] += size[x_leader];
			}
		}
	}


};


signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, q;
	cin >> n >> m >> q;

	disjoint_set dsu(n);

	vector<vector<int>> record(q, vector<int>(3));
	char c;
	set<pair<int, int>> relation;
	int u, v;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (u > v) {
			relation.insert(pair<int, int>(v, u));
		}
		else {
			relation.insert(pair<int, int>(u, v));
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> c >> record[i][1] >> record[i][2];
		if (c == 'A') {
			record[i][0] = 0;
		}
		else {
			record[i][0] = 1;
			if (record[i][1] > record[i][2]) {
				auto it = relation.find(pair<int, int>(record[i][2], record[i][1]));
				if (it != relation.end()) {
					relation.erase(it);
				}
			}
			else {
				auto it = relation.find(pair<int, int>(record[i][1], record[i][2]));
				if (it != relation.end()) {
					relation.erase(it);
				}
			}
		}
	}

	for (auto it = relation.begin(); it != relation.end(); it++) {
		dsu.merge(it->first, it->second);
	}

	vector<bool> reply;
	
	for (int i = q - 1; i >= 0; i--) {
		if (record[i][0] == 0) {
			if (dsu.find(record[i][1]) == dsu.find(record[i][2])) {
				reply.push_back(true);
			}
			else {
				reply.push_back(false);
			}
		}
		else {
			dsu.merge(record[i][1], record[i][2]);
		}
	}

	for (auto it = reply.rbegin(); it != reply.rend(); it++) {
		if (*it) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	



	return 0;
}