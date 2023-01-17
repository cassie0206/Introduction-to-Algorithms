#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long
using namespace std;


int lbs1(vector<int> &v, int n) {
	vector<long double> increase, decrease;
	vector<int> tail_i, tail_d;
	v.resize(n);
	tail_i.resize(n);
	tail_d.resize(n);


	for (int i = 0; i < n; i++) {
		if (i == 0) {			
			increase.push_back(v[i]);

		}
		else {
			if (v[i] < increase[0]) {
				increase[0] = v[i];
				tail_i[0] = 1;
			}
			else if (v[i] > *(--increase.end())) {
				increase.push_back(v[i]);
				tail_i[i] = increase.size();
			}
			else {
				vector<long double>::iterator it = lower_bound(increase.begin(), increase.end(), v[i]);
				*it = v[i];
				tail_i[i] = it - increase.begin() + 1;
			}
		}
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			decrease.push_back(v[i]);

		}
		else {
			if (v[i] < decrease[0]) {
				decrease[0] = v[i];
				tail_d[0] = 1;
			}
			else if (v[i] > *(--decrease.end())) {
				decrease.push_back(v[i]);
				tail_d[i] = decrease.size();
			}
			else {
				vector<long double>::iterator it = lower_bound(decrease.begin(), decrease.end(), v[i]);
				*it = v[i];
				tail_d[i] = it - decrease.begin() + 1;
			}
		}
	}

	reverse(tail_d.begin(), tail_d.end());

	int large = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		large = max(large, tail_i[i] + tail_d[i]);
	}
	return large - 1;
}



signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v;
	v.resize(n);

	vector<int> v2=v;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v2[i] = -v[i];
	}

	lbs1(v, n);
	lbs1(v2, n);

	cout << max(lbs1(v, n), lbs1(v2, n));

	return 0;
}