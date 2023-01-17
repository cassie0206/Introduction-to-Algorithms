#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define int long long
using namespace std;


signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int t;
	cin >> t;

	vector<int> col;
	col.resize(t);

	for (int i = 0; i < t; i++) {
		cin >> col[i];
	}

	int large = *max_element(col.begin(), col.end());
	vector<vector<int>> m(2, vector<int>(large - 1));
	int last = 5;
	m[0][0] = 2;
	m[1][0] = 1;
	m[0][1] = 5;
	m[1][1] = 3;


	for (int i = 2; i < large - 1; i++) {
		for (int j = 1; j >= 0; j--) {
			if (j == 0) {
				m[j][i] = (++last) + m[j + 1][i - 1];
			}
			else {
				m[j][i] = (++last) + m[j - 1][i - 2];
			}
			last = m[j][i] % 1000000007;
		}
	}

	int ans = 0;

	for (int i = 0; i < t; i++) {
		if (col[i] == 1) {
			cout << "1\n";
		}
		else {
			ans = m[0][col[i] - 2];
			ans = 4 * ans + 1;
			ans %= 1000000007;
			cout << ans << "\n";
		}
	}



	return 0;
}