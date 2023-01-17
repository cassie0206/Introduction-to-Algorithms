#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<long long> vec;
long long calcu(vector<long long>, int, int);

int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	if (N == 1 || N == 2) cout << 0;
	else cout << calcu(vec, 0, N - 1);

	return 0;
}


long long calcu(vector<long long> vec, int front, int back) {


	long long a = 0, b = 0;

	if ((back - front) == 3) {

		long long tmpa = (vec[front + 1] - vec[front]);
		long long tmpb = vec[back] - vec[back - 1];
		if (tmpa < 0)tmpa = -tmpa;
		if (tmpb < 0)tmpb = -tmpb;
		long long tmp = min(tmpa, tmpb);
		return tmp;

	}
	else if ((back - front) == 1) {

		long long tmpa = (vec[front + 1] - vec[front]);
		long long tmpb = vec[back] - vec[back - 1];
		if (tmpa < 0)tmpa = -tmpa;
		if (tmpb < 0)tmpb = -tmpb;
		long long tmp = min(tmpa, tmpb);
		return tmp;

	}
	else if ((back - front) == 2)return 0;

	int mid = (front + back) / 2;

	vector<long long> first;
	vector<long long> second;

	first.assign(vec.begin(), vec.begin() + mid + 1);
	second.assign(vec.begin() + mid + 1, vec.end());

	int secmid = (front + mid) / 2;

	vector<long long> tmplft = first;
	vector<long long> tmprgt = second;


	nth_element(first.begin(), first.begin() + secmid, first.end());
	nth_element(second.begin(), second.begin() + secmid, second.end());


	for (int i = 0; i < first.size(); i++) {
		if ((first[i] - first[secmid]) > 0) a += (first[i] - first[secmid]);
		else a += (first[secmid] - first[i]);

	}


	for (int i = 0; i < second.size(); i++) {
		if ((second[i] - second[secmid]) > 0) b += (second[i] - second[secmid]);
		else b += (second[secmid] - second[i]);

	}

	return min(calcu(tmplft, front, mid) + b, calcu(tmprgt, 0, (second.size() - 1)) + a);

}