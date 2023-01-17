#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>
#define int long long
using namespace std;

class graph {
	int n;
	vector<map<int, int>> matrix;
	vector<bool> visit;
	vector<int> p;
public:
	graph(int n) {
		this->n = n;
		matrix.resize(n + 2);
		visit.resize(n + 2);
		p.resize(n + 2);
	}

	void addEdge(int u, int v, int w) {
		matrix[u].insert(pair<int, int>(v, w));
	}

	bool BFS() {
		for (int i = 0; i < n + 2; i++) {
			p[i] = -1;
			visit[i] = false;
		}

		visit[0] = true;
		queue<int> q;
		q.push(0);

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			visit[u] = true;

			for (auto it = matrix[u].begin(); it != matrix[u].end(); it++) {
				int v = it->first;
				int w = it->second;

				if (!visit[v] && w > 0) {
					p[v] = u;
					q.push(v);
					if (v == n + 1) {
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
	

			for (int i = n + 1; i != 0; i = p[i]) {
				int parent = p[i];
				auto it = matrix[parent].find(i);

				flow = min(flow, it->second);
			}

			for (int i = n + 1; i != 0; i = p[i]) {
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

	int n, a, b, m, x, y, c;
	cin >> n;
	graph g(n);


	for (int i = 0; i < n; i++) {
		cin >> a;
		g.addEdge(0, i + 1, a);
	}

	for (int i = 0; i < n; i++) {
		cin >> b;
		g.addEdge(i + 1, n + 1, b);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;
		g.addEdge(x, y, c);
		g.addEdge(y, x, c);
	}

	g.fordFulkerson();


	return 0;
}