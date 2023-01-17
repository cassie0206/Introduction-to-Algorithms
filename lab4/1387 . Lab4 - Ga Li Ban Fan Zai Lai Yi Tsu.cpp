#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#define int long long
using namespace std;

vector<int> least;
vector<int> value;

int change_money(int n) {
	if (n == 0) {
		least[0] = 0;
		return 0;
	}
	else if (least[n] != 0) {
		return least[n];
	}
	else {
		int small = INT_MAX;
		for (int i = 0; i < value.size(); i++) {
			if (n >= value[i]) {
				small = min(small , change_money(n - value[i]) + 1);
			}
		}
	
		least[n] = small;
		return least[n];
	}
}


signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int n;
	cin >> n;

	vector<int> money;
	value.resize(n);
	money.resize(n + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}

	int q, sum = 0, change_max = -1, change = 0;
	vector<int> v_change;
	cin >> q;
	v_change.resize(q);

	for (int i = 0; i < q; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> money[j];
			if (j == 0) {
				change -= money[j];
			}
			else {
				change += money[j] * value[j - 1];
			}
		}
		change_max = max(change_max, change);
		v_change[i] = change;
		change = 0;
	}

	least.resize(change_max + 1, 0);
	change_money(change_max);

	for (int i = 0; i < q; i++) {
		cout << least[v_change[i]] << endl;
	}


	return 0;
}