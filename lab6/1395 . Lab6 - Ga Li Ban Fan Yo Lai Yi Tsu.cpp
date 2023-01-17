#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

class graph {
	int f, n, m, k;
	vector<map<int, int>> matrix;
	vector<bool> visit;
	vector<int> p;
public:
	graph(int f, int n, int m) {
		this->f = f;
		this->n = n;
		this->m = m;

		matrix.resize(f + 2 * n + m + 3);
		visit.resize(f + 2 * n + m + 3);
		p.resize(f + 2 * n + m + 3);
	}

	void addEdge(int u, int v, int w) {

		auto it = matrix[u].find(v);
		if (it != matrix[u].end()) {
			it->second += w;
		}
		else {
			matrix[u].insert(pair<int, int>(v, w));
		}
	}

	void getK(int k) {
		this->k = k;
		matrix[f + 2 * n + m + 1].insert(pair<int, int>(f + 2 * n + m + 2, k));
	}

	bool BFS() {

		for (int i = 0; i < f + 2*n + m + 3; i++) {
			p[i] = -1;
		}
		for (int i = 0; i < f + 2*n + m + 3; i++) {
			visit[i] = false;
		}
		queue<int> q;
		q.push(0);
		visit[0] = true;


		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			visit[cur] = true;

			for (auto it = matrix[cur].begin(); it != matrix[cur].end(); it++) {

				int u = it->first;
				int w = it->second;


				if (!visit[u] && w > 0) {
					p[u] = cur;
					q.push(u);
					if (u == f + 2*n + m + 2) {
						return true;
					}
				}
			}

		}

		return false;

	}

	void fordFulkerson() {
		int maxFlow = 0;

		while (BFS()) {
			int flow = LLONG_MAX;
	
			for (int i = f + 2*n + m + 2; i != 0; i = p[i]) {
				int parent = p[i];
				auto it = matrix[parent].find(i);

				flow = min(flow, it->second);
				
			}

			for (int i = f + 2*n + m + 2; i != 0; i = p[i]) {
				int parent = p[i];
				auto it = matrix[parent].find(i);
				auto itr = matrix[i].find(parent);

				it->second -= flow;
				if (itr != matrix[i].end()) {
					itr->second += flow;
				}
				else {
					matrix[i].insert(pair<int, int>(parent, flow));
				}
			}

			maxFlow += flow;
		}

		cout << maxFlow;
	}

};


signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int f, n, m, l, p, s, c, x, y, w, t, k;
	cin >> f >> n >> m;
	graph g(f, n, m);

	for (int i = 0; i < f; i++) {
		cin >> l;
		g.addEdge(0, i + 1, l);
	}

	for (int i = 0; i < 2 * n; i += 2) {
		cin >> p;
		g.addEdge(f + 1 + i, f + 2 + i, p);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		g.addEdge(f + 2 * n + 1 + i, f + 2 * n + m + 1, s);
	}

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> x >> y >> w;
		y = 2 * y + f - 1;
		g.addEdge(x, y, w);
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y >> w;
		x = 2 * x + f;
		y = y + f + 2 * n;
		g.addEdge(x, y, w);
	}

	cin >> k;
	g.getK(k);

	g.fordFulkerson();

	return 0;
}