#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	long long int n, l, k, w;
	cin >> n >> l >> k;
	multiset<long long int> set;
	for (int i = 0; i < n; i++) {
		cin >> w;
		set.insert(w);
	}
	int time = 0;
	while (!set.empty()) {
		multiset<long long int>::iterator it = set.end();
		it--;
		if (set.size() != 1) {
			if (*(it)+*(set.begin()) <= l) { time++; set.erase(it); set.erase(set.begin()); }
			else { time++; set.erase(it); }
		}
		else { set.clear(); time++; }
	}
	cout << time * k * 2;
	





	return 0;
}