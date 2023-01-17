#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#define int long long

using namespace std;

class graph {
	int n, scc = 0;
	vector<vector<int>> matrix, Tmatrix, scc_matrix;
	stack<int> s;
	vector<bool> visit;
	vector<int> num, p, in;
public:
	graph(int n) {
		this->n = n;
		matrix.resize(n);
		Tmatrix.resize(n);
	}

	void addEdge(int u, int v) {
		matrix[u].push_back(v);
	}

	void ini_visit() {
		visit.resize(n, false);
	}

	void dfs(int start) {
		visit[start] = true;

		for (int i = 0; i < matrix[start].size(); i++) {
			if (visit[matrix[start][i]] == false) {
				dfs(matrix[start][i]);
			}
		}

		s.push(start);
		return;
	}

	void DFS() {
		while (s.size() < n) {
			for (int i = 0; i < n; i++) {
				if (visit[i] == false) {
					dfs(i);
				}
			}
		}
	}

	void graphTtranspose() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				Tmatrix[matrix[i][j]].push_back(i);
			}
		}
	}

	void Tdfs(int start) {
		visit[start] = true;

		for (int i = 0; i < Tmatrix[start].size(); i++) {
			if (visit[Tmatrix[start][i]] == false) {
				Tdfs(Tmatrix[start][i]);
			}
		}

		s.push(start);
	
		return;
	}

	void findSCC() {
		vector<int> origin_s;
		origin_s.resize(n);
		for (int i = 0; i < n; i++) {
			origin_s[i] = s.top();
			s.pop();
		}

		for (int i = 0; i < n; i++) {
			visit[i] = false;
		}

		num.resize(n);
		p.resize(n);
		for (int i = 0; i < n; i++) {
			if (visit[origin_s[i]] == false) {
				Tdfs(origin_s[i]);
				int size = s.size();
				int leader = s.top();
				num[s.top()] = size;
				while (!s.empty()) {
					p[s.top()] = leader;
					num[s.top()] = size;
					s.pop();
				}
				scc++;
			}
		}

	}

	void build() {
		scc_matrix.resize(n);
		in.resize(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (p[i] != p[matrix[i][j]]) {
					scc_matrix[p[i]].push_back(p[matrix[i][j]]);
					in[p[matrix[i][j]]]++;
				}
			}
		}
	}

	void topo() {
		queue<int> q;
		vector<int> dp(n, 0);

		for (int i = 0; i < n; i++) {
			if (in[i] == 0 && i == p[i]) {
				q.push(i);
				dp[i] = num[i];
			}
		}

		int large = LLONG_MIN;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			large = max(large, dp[cur]);

			for (int i = 0; i < scc_matrix[cur].size(); i++) {
				dp[scc_matrix[cur][i]] = max(dp[scc_matrix[cur][i]], dp[cur] + num[scc_matrix[cur][i]]);
				in[scc_matrix[cur][i]]--;
				if (in[scc_matrix[cur][i]] == 0) {
					q.push(scc_matrix[cur][i]);
				}
			}
		}
	
		cout << large;


	}



};



signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, u, v;
	cin >> n >> m;
	graph g(n);

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g.addEdge(u, v);
	}

	g.ini_visit();
	g.DFS();

	g.graphTtranspose();
	g.findSCC();

	g.build();
	g.topo();



	return 0;
}