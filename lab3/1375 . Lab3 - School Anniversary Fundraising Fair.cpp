#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define int long long

void clear(priority_queue<int>& q) {
	priority_queue<int> empty;
	swap(q, empty);
}


signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int  n, p, target_l, target_r, l, r, sum = 0;
	cin >> n >> p;
	cin >> target_l >> target_r;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	priority_queue<int> q_r;
	
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		q.push(pair<int, int>(l, r));
	}

	while (target_l < target_r) {
		clear(q_r);
		while (!q.empty()&&q.top().first<=target_l) {
			if (q.top().second > target_l) {
				q_r.push(q.top().second); q.pop();
			}
			else {
				q.pop();
			}
		}
		if (q_r.empty()) { cout << "0"; break; }
		target_l = q_r.top();
		sum += p;
	}
	if (target_l>=target_r) { cout << sum; }

	return 0;
}