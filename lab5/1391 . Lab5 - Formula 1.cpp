#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int long long
using namespace std;

vector<vector<pair<int, int>>> path;
int fee = 0;

class disjoint_set {
public:
	int n;
	vector<int> p, size; //fee;
	disjoint_set(int n) {
		this->n = n;
		p.resize(n + 1);
		size.resize(n + 1, 0);
		//fee.resize(n + 1, 0);
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
	}
	
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}

	void merge(int x, int y) {
		int x_leader = find(x);
		int y_leader = find(y);

		if (size[x_leader] >= size[y_leader]) {
			p[y_leader] = x_leader;
			size[x_leader] += size[y_leader];
		}
		else {
			p[x_leader] = y_leader;
			size[y_leader] += size[x_leader];
		}
	}

};

int cal_fee(int index, int p, int n) {
	if (path[index].size() == 1 && path[index][0].first == p) {
		fee += ((1 * ((n - 1) * (path[index][0].second % 1000000007))) % 1000000007);
		return 1;
	}
	else {
		int sum = 0;
		int w = 0;
		for (int i = 0; i < path[index].size(); i++) {
			if (path[index][i].first == p) {
				w = path[index][i].second;
				continue;
			}
			else {
				sum += cal_fee(path[index][i].first, index, n);
				sum %= 1000000007;
			}
		}
		fee += (((++sum) * (((n - sum) * (w % 1000000007)) % 1000000007)) % 1000000007);
		return sum;
	}
}

class graph {
	int n, m;
	vector<vector<int>> edge;
public:
	graph(int n, int m) {
		this->n = n;
		this->m = m;
		disjoint_set dsu(n);
	}
	
	void addEdge(int u, int v, int c) {
		edge.push_back({ c,u,v });
	}

	void MST() {
		sort(edge.begin(), edge.end());

		disjoint_set dsu(n);
		path.resize(n + 1);
		path[0].resize(1, pair<int, int>(0, 0));
		
		int time = 0, cost = 0;
		for (int i = 0; i < m; i++) {
			if (time == n - 1) {
				break;
			}
			if (dsu.find(edge[i][1]) != dsu.find(edge[i][2])) {
				cost += edge[i][0];
				cost % 1000000007;
				time++;
				dsu.merge(edge[i][1], edge[i][2]);

				path[edge[i][1]].push_back(pair<int, int>(edge[i][2], edge[i][0]));
				path[edge[i][2]].push_back(pair<int, int>(edge[i][1], edge[i][0]));
			}
			else {
				continue;
			}
		}

		if (time != n - 1) {
			cout << "-1";
		}
		else {
			cout << (cost * 2) % 1000000007 << " ";
			cal_fee(1, 0, n);
			cout << (fee * 2) % 1000000007;
		}

	}


};

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	graph g(n, m);
	int u, v, c;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		g.addEdge(u, v, c);
	}

	g.MST();


	return 0;
}