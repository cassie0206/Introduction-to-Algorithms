#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long

using namespace std;

void clear(priority_queue<int>& q) {
	priority_queue<int> empty;
	q = empty;
}

signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, t;
	cin >> n >> t;

	vector<vector<int>> v(t, vector<int>(n + 2, -10000000000000));

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j + 1];
		}
	}

	int sum = 0, key = 0;
	priority_queue<int> q;

	for (int i = t - 1; i > 0; i--) {
		for (int j = 0; j < n; j++) {
			q.push(v[i][j]);
			q.push(v[i][j + 1]);
			q.push(v[i][j + 2]);
			v[i - 1][j + 1] += q.top();
			clear(q);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << v[0][i + 1] << " ";
	}


	return 0;
}