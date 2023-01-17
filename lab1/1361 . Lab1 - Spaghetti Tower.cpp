#include <iostream>
#include <set>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	long long int n, k, s, x, l;
	int q;
	vector<long long int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cin >> q;
	long long int time = 0;
	for (int i = 0; i < q; i++) {
		cin >> x >> l;
		for (int j = 1; j < k&&j*x<l; j++) {
			if ((j + 1) * x > l) {
				time += (lower_bound(v.begin(), v.end(), l) - lower_bound(v.begin(), v.end(), j * x)) * j;
			}
			else {			
				time += (lower_bound(v.begin(), v.end(), (j + 1) * x) - lower_bound(v.begin(), v.end(), j * x)) * j;
			}
		}
		if(x*k<l){
			time += (upper_bound(v.begin(),v.end(),x*k)-lower_bound(v.begin(),v.end(),x*k))* k;
		}
		else{
			time += (upper_bound(v.begin(),v.end(),l)-lower_bound(v.begin(),v.end(),l))* (l/x);
		}
		cout << time << "\n"; time = 0;
	}
	return 0;
}