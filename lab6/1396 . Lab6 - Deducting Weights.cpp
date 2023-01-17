#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>

#define int long long
using namespace std;

class graph {
	int n, m;
	vector<int> dis1, dis2;
	vector<vector<pair<int, int>>> matrix1, matrix2;
	vector<vector<int>> record;
public:
	graph(int n, int m) {
		this->n = n;
		this->m = m;
		dis1.resize(n + 1, LLONG_MAX);
		dis1[1] = 0;
		dis2.resize(n + 1, LLONG_MAX);
		dis2[n] = 0;
		matrix1.resize(n + 1);
		matrix2.resize(n + 1);
	}

	void addRecord(int u, int v, int w) {
		record.push_back({ u,v,w });
	}

	void addEdge(int u, int v, int w) {
		matrix1[u].push_back(pair<int, int>(v, w));
		matrix2[v].push_back(pair<int, int>(u, w));
	}

	vector<int>* getDis(int type) {
		switch (type) {
		case 0:
			return &dis1;
			break;
		case 1:
			return &dis2;
			break;
		}
	}

	vector<vector<pair<int, int>>>* getMatrix(int type) {
		switch (type) {
		case 0:
			return &matrix1;
			break;
		case 1:
			return &matrix2;
			break;
		}
	}

	void dijkstra(int s, vector<int>& dis, vector<vector<pair<int, int>>>& matrix) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push(pair<int, int>(0, s));

		while (!q.empty()) {
			int cur = q.top().second;
			q.pop();

			for (int i = 0; i < matrix[cur].size(); i++) {
				int v = matrix[cur][i].first;
				int w = matrix[cur][i].second;

				if (dis[v] > dis[cur] + w) {
					dis[v] = dis[cur] + w;
					q.push(pair<int, int>(dis[v], v));
				}

			}

		}

	}

	void print() {
		int ans;

		for (int i = 0; i < m; i++) {

			ans = dis1[record[i][0]] + dis2[record[i][1]] + record[i][2] - dis1[n];
			if (ans > record[i][2]|| dis1[record[i][0]]==LLONG_MAX|| dis2[record[i][1]]==LLONG_MAX) {//1.因為他需要檢調比自己那條邊的權重還大的數字才能變shortest path
																									//這樣那條邊需要是負的才可以，不成立2.如果是llong_max會overflow變負的
				cout << "-1\n";
			}
			else {
				cout << ans << "\n";
			}

		}
	}

};



signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int  n, m, u, v, w;
	cin >> n >> m;
	graph g(n, m);

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
		g.addRecord(u, v, w);
	}

	g.dijkstra(1, *g.getDis(0), *g.getMatrix(0));
	g.dijkstra(n, *g.getDis(1), *g.getMatrix(1));

	g.print();


	return 0;
}