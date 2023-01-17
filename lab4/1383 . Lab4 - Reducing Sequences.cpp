#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long
using namespace std;

signed main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> val(n);
	vector<vector<int>> sum(n, vector<int>(n, 0)), reward(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		cin >> val[i];
		sum[i][i] = val[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 2; j < n; j += 2) {
			sum[i][j] = val[j] + val[j - 1] + sum[i][j - 2];
		}
	}

	for (int j = 2; j < n; j++) {//下界
		for (int i = j - 2; i >= 0; i -= 2) {//上界
			reward[i][j] = LLONG_MIN;
			for (int k = j - 2; k >= i; k -= 2) {//切割 從後面開始
				reward[i][j] = max(reward[i][j], reward[i][k] + reward[k + 2][j] + sum[i][k] * sum[k + 2][j] - sum[k + 1][k + 1]);
			}
			if (j - i != 2) {//如果subsequence的長度大於三 考慮從中間融合 再兩邊
				reward[i][j] = max(reward[i][j], sum[i][i] * sum[j][j] - sum[i + 1][j - 1] + reward[i + 1][j - 1]);
			}
		}
	}


	cout << reward[0][n - 1];


	return 0;
}