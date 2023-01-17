#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define int long long

using namespace std;

signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int n, c, q, k, sum = 0;
	cin >> n >> c >> q;
	vector<vector<int>> v;
	vector<int> order, key(n + 1, 0);//key是現在在哪
	set<pair<int, int>> core;//(next index,value)
	set<int> core_value;
	v.resize(n + 1);
	order.resize(q);

	for (int i = 0; i < q; i++) {
		cin >> k;
		v[k].push_back(i);
		order[i] = k;
	}

	for (int i = 0; i < q; i++) {
		if (key[order[i]] < v[order[i]].size()) {
			set<int>::iterator it = core_value.find(order[i]);
			set<pair<int, int>>::iterator iter = core.find(pair<int, int>(v[order[i]][key[order[i]]], order[i]));
			if (it != core_value.end()) {//有一樣的
				core.erase(iter);
				key[order[i]]++;
				//v[order[i]].pop();
				if (key[order[i]]<v[order[i]].size()) {
					core.insert(pair<int, int>(v[order[i]][key[order[i]]], order[i]));
				}
				else {
					core.insert(pair<int, int>(1000000, order[i]));
				}
			}
			else {//沒有一樣的
				if (core_value.size() < c) {//還有initial
					core_value.insert(order[i]);
					key[order[i]]++;
					//v[order[i]].pop();
					if (key[order[i]] < v[order[i]].size()) {
						core.insert(pair<int, int>(v[order[i]][key[order[i]]], order[i]));
					}
					else {
						core.insert(pair<int, int>(1000000, order[i]));
					}
				}
				else {//沒有initial
					core_value.erase(core_value.find((--core.end())->second));
					core_value.insert(order[i]);
					key[order[i]]++;
					core.erase(--core.end());
					
					if (key[order[i]] < v[order[i]].size()) {
						core.insert(pair<int, int>(v[order[i]][key[order[i]]], order[i]));
					}
					else {
						core.insert(pair<int, int>(1000000, order[i]));
					}
				}

				sum++;
			}
		}
	}
	cout << sum << "\n";


	return 0;
}