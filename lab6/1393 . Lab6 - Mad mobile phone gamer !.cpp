#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define int long long

class graph {
	int n;
	vector<vector<int>> dp;
public:
	graph(int n) {
		this->n = n;
		dp.resize(n, vector<int>(n, LLONG_MAX));

		for (int i = 0; i < n; i++) {
			dp[i][i] = 0;
		}
	}

	void addEdge(int u, int v, int c) {
		dp[u][v] = min(dp[u][v], c);
	}

	void FloydWarshall() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dp[i][k] != LLONG_MAX && dp[k][j] != LLONG_MAX) {
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
					}
				}
			}
		}
	}

	void print(int u, int v) {
		if (dp[u][v] != LLONG_MAX) {
			cout << dp[u][v] << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
};


signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, a, b, w, k, f, t;
	cin >> n >> m;
	graph g(n);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		g.addEdge(a, b, w);
	}
	
	g.FloydWarshall();

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> f >> t;
		g.print(f, t);
	}



	return 0;
}