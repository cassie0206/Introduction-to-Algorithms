#include <iostream>
#include <vector>
#include <utility>
#define int long long
using namespace std;

class disjoint_set {
public:
	int n;
	vector<int> p, size; //fee;
	disjoint_set(int n) {
		this->n = n;
		p.resize(n + 1);
		size.resize(n + 1, 0);
		
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

class graph {
	int n, m, f_m = 0, s_m = 0;
	vector<vector<int>> matrix, fmatrix, smatrix;
public:
	graph(int n, int m) {
		this->n = n;
		this->m = m;
	}

	void addEdge(int u, int v, int type) {
		matrix.push_back({ u,v,type });

		switch (type) {
		case 0:
			fmatrix.push_back({ u,v });
			f_m++;
			break;
		case 1:
			smatrix.push_back({ u,v });
			s_m++;
			break;
		}
	}

	bool MST() {
		disjoint_set dsu(n);

		int time = 0;
		for (int i = 0; i < matrix.size(); i++) {
			if (time == n - 1) {
				break;
			}
			if (dsu.find(matrix[i][0]) != dsu.find(matrix[i][1])) {
				time++;
				dsu.merge(matrix[i][0], matrix[i][1]);
			}
			else {
				continue;
			}
		}

		if (time != n - 1) {
			return false;
		}
		else {
			return true;
		}

	}

	vector<vector<int>>* getMatrix(int type) {
		if (type == 0) {
			return &fmatrix;
		}
		else {
			return &smatrix;
		}
	}

	int subMST(vector<vector<int>>& sub_matrix) {
		disjoint_set  dsu(n);
		int sub_m = sub_matrix.size();

		int time = 0;
		for (int i = 0; i < sub_m; i++) {
			if (time == n - 1) {
				return time;
			}
			if (dsu.find(sub_matrix[i][0]) != dsu.find(sub_matrix[i][1])) {
				time++;
				dsu.merge(sub_matrix[i][0], sub_matrix[i][1]);
			}
		}
		return time;
	}


};



signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int t, n, m, k, f, s, u, v;
	char type;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k >> f >> s;
		graph g(n, m);

		for (int j = 0; j < m; j++) {
			cin >> u >> v >> type;
			switch (type) {
			case 'F'://F=0
				g.addEdge(u, v, 0);
				break;
			case 'S'://S=1
				g.addEdge(u, v, 1);
				break;
			}
		}

		if (!g.MST()) {
			cout << "No\n";
		}
		else {
			int uf = g.subMST(*g.getMatrix(0));//upper bound for f
			int us = g.subMST(*g.getMatrix(1));//upper bound for s

			int lf = (n - 1) - us;//lower bound for f
			int ls = (n - 1) - uf;//lower bound for s

			if (uf < lf || us < ls) {
				cout << "No\n";
			}
			else {
				int ans = 0;
				for (int j = lf; j <= uf; j++) {
					ans = k - f * j;
					
					if (ans % s == 0) {
						ans /= s;
					
						if (ans + j == n - 1 && ans >= ls && ans <= us) {//1st condition is because the whole graph is also MST
							cout << "Yes\n";
							break;
						}
					}
					if (j == uf) {
						cout << "No\n";
					}
				}
			}
		}

	}


	return 0;
}