#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

class graph {
	int n, negative;
	vector<vector<int>> matrix;
	vector<int> dis, vec;
public:
	graph(int n) {
		this->n = n;
	}

	void addEdge(int u, int v, int w) {
		matrix.push_back({ w,u,v });
		vec.push_back(w);
	}

	void getNegative(int x) {
		this->negative = x;
	}

	bool BellmanFord(int k) {
		dis.resize(n, 0);

		for (int i = 0; i < n - 1; i++) {
			for (int j = k; j < matrix.size(); j++) {
				dis[matrix[j][2]] = min(dis[matrix[j][2]], dis[matrix[j][1]] + matrix[j][0]);
			}
		}

		for (int j = k; j < matrix.size(); j++) {
			if (dis[matrix[j][2]] > dis[matrix[j][1]] + matrix[j][0]) {
				return true;//there is a negative cycle
			}
		}

		dis.clear();

		return false;//no negative cycle
	}

	void detec() {
		sort(matrix.begin(), matrix.end());
		sort(vec.begin(), vec.end());

		if (!BellmanFord(0)) {
			cout << "GO AHEAD";
		}
		else {
			int l = 0, r = matrix.size(), mid = (l + r) / 2, lastMid;

			while (r - l > 1) {
				bool existCycle = BellmanFord(mid);

				if (!existCycle) {
					r = mid;
					mid = (l + r) / 2;

				}
				else {
					l = mid;
					mid = (l + r) / 2;
				}

			}

			if (matrix[l][0] < 0 && matrix[r][0] < 0) {
				if (matrix[l][0] == matrix[r][0] && upper_bound(vec.begin(), vec.end(), matrix[r][0]) != vec.end() &&*upper_bound(vec.begin(), vec.end(), matrix[r][0]) >= 0) {
					cout << "NO WAY BACK";
					return;
				}

				cout << matrix[l][0];
				return;
			}
			else {
				cout << "NO WAY BACK";
				return;
			}

		}

	}
};

signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, s, t, d, negative = 0;
	cin >> n >> m;
	graph g(n);

	for (int i = 0; i < m; i++) {
		cin >> s >> t >> d;
		g.addEdge(s, t, d);
		if (d < 0) {
			negative++;
		}
	}

	g.getNegative(negative);
	g.detec();

	return 0;
}