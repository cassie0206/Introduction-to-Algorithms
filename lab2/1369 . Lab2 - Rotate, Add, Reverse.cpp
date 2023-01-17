#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> rotate(vector<int> a,vector<int> b) {
	b.insert(b.begin(), a.begin(), a.end());
	return b;
}

vector<int> add(vector<int> v, int k) {
	/*for (int i = 0; i < v.size(); i++) {
		v[i] += k;
	}*/
	vector<int> v_add(v.size(), k);
	vector<int> v_final; v_final.resize(v.size());
	transform(v.begin(), v.end(), v_add.begin(), v_final.begin(), plus<int>());

	return v_final;
}

vector<int> reverse(vector<int> v) {
	reverse(v.begin(), v.end());
	return v;
}

void recursion(vector<int>& v,const int n,int time) {
	if (time > n) { 
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		return; 
	}
	else {
		v=rotate(add(v, pow(2, time - 1)), reverse(v));
		time++;
		recursion(v, n, time);
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int n;
	cin >> n;

	vector<int> s(1, 1);
	recursion(s, n, 1);


	return 0;
}