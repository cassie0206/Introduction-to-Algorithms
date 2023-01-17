#include <iostream>
#include <set>
using namespace std;


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	long long int n;
	long long int c;
	cin >> n;
	multiset<long long int> set;
	long long int p = 1;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c > n) { set.insert(n); }
		else{ set.insert(c); }
	}
	int i = 0;
	for (auto it = set.begin(); it != set.end(); it++) {
		p *= ((*it - i) % (1000000007));
		p %= 1000000007;
		i++;
	}
	cout << p ;

	return 0;
}