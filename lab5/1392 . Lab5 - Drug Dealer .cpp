#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define int long long
using namespace std;

class graph {
	int n;
	vector<vector<int>> matrix;
	vector<bool> cop;
public:
	graph(int n) {
		this->n = n;
		matrix.resize(n + 1);
		cop.resize(n + 1, false);
	}

	void addEdge(int u, int v) {
		matrix[u].push_back(v);
		matrix[v].push_back(u);
	}

	void setCop(int x) {
		cop[x] = true;
	}

	bool BFS(int start, int ta) {
		queue<pair<int,int>> q;//index,time
		q.push(pair<int, int>(start, 0));
		
		vector<bool> visit(n + 1, false);
		int tag = 3000000;

		while (!q.empty()) {
			int cur = q.front().first;
			int time = q.front().second;
			q.pop();
			visit[cur] = true;
			
			time++;
			for (int i = 0; i < matrix[cur].size(); i++) {
				
				if (!visit[matrix[cur][i]]) {
					q.push(pair<int, int>(matrix[cur][i], time));
					if (cop[matrix[cur][i]]) { 
						if (tag != 3000000 && tag < time) {
							return true;
						}
						return false;
					}
					if (matrix[cur][i] == ta) {
						tag = time;
					}


				}
			}
		}
	}

};

signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int t, n, m, s, u, v, x, y, a, b;
	vector<int> hide, cop;
	cin >> t;
	

	for (int i = 0; i < t; i++) {
		cin >> n >> m >> s;
		graph g(n);
		
		for (int j = 0; j < m; j++) {
			cin >> u >> v;
			g.addEdge(u, v);
		}

		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> a;
			g.setCop(a);
		}

		cin >> y;
		for (int j = 0; j < y; j++) {
			cin >> b;
			hide.push_back(b);
		}

		bool suc = false;
		for (int j = 0; j < y; j++) {
			
			suc = g.BFS(hide[j], s);

			if (suc) { 
				cout << "Yes\n"; 
				break; 
			}
		}

		if (!suc) { 
			cout << "No\n"; 
		}

		hide.clear();

	}


	return 0;
}