#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <queue>
#define int long long

using namespace std;


double formula(long double p, long double x, long double n) {
	return p * x / ((x + n + 1) * (x + n));
}


signed main() {
	cin.tie(0); cin.sync_with_stdio(0);

	int n, k;//num=the number of teammate
	long double p, x, num, sum = 0;
	cin >> n >> k;
	vector<pair<long double, long double>> v;//(p,x)=>(point,original number of people)
	vector<long double> v_num;
	priority_queue<pair<long double, int>> q;//(value,index of furniture)
	v.resize(n);
	v_num.resize(n, 0);


	for (int i = 0; i < n; i++) {
		cin >> p >> x;
		v[i] = pair<long double, long double>(p, x);
		q.push(pair<long double, int>(v[i].first / (long double)(v[i].second + 1), i));
	}
	
	for (int i = 0; i < k; i++) {
		if (v[q.top().second].second == 0 && v_num[q.top().second] == 0) {
			sum += q.top().first;
			v_num[q.top().second] += 1;
			q.pop();
		}
		else {
			sum += q.top().first;
			v_num[q.top().second] += 1;
			q.push(pair<long double, int>(formula(v[q.top().second].first, v[q.top().second].second, v_num[q.top().second]), q.top().second));
			q.pop();
		}
	}
	cout << fixed << setprecision(10) << sum;


	return 0;
}