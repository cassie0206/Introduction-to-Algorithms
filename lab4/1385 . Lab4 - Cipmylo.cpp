#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#define int long long 

using namespace std;


signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m, s, y, b, e, v;
	cin >> n >> m >> s;

	vector<int> year;
	vector<pair<int, int>> pandemic;
	year.resize(n);


	for (int i = 0; i < n; i++) {
		cin >> year[i];
	}
	sort(year.begin(), year.end());


	int sum = 0, num = 0;
	vector<int>::iterator begin, end;
	
	for (int i = 0; i < m; i++) {
		cin >> b >> e >> v;
		begin = lower_bound(year.begin(), year.end(), b);
		end = upper_bound(year.begin(), year.end(), e);
		num = end-begin;
		sum += num;
		pandemic.push_back(pair<int, int>(v, num));
	}
	sum = n - sum;

	vector<int> weight, value;
	weight.resize(m);
	value.resize(m);

	auto it = --pandemic.end();
	for (int i = 0; i < weight.size(); i++) {
		weight[i] = it->first;
		value[i] = it->second;
		it--;
	}

	vector<int> dp(s + 1, 0);

	for (int i = 0; i < m; i++) {
		for (int j = s; j >= 0; j--) {
			if (weight[i] <= j) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
	}

	cout << dp[s] + sum;



	return 0;
}