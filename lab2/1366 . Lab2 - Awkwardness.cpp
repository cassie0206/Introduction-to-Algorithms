#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<long long> senority, post_order, index_inorder, in_order;
long long sum = 0;
//vector<pair<long long, long long>> in_order;


//root代表他在inorder的位置index
//void f()
void awkwardness(long long root, long long il, long long iu, long long pl, long long pu,long long& sum) {
	if (iu == il || pu == pl) { 
		return; 
    }
	long long ro_num = 0;
	ro_num = iu - root;
	//cout << "root: " << root << endl;
	if (ro_num > 0) {	
		if (senority[in_order[root]] < senority[post_order[pu - 1]]) {
			sum++;
			//cout << "a. " << index_inorder[root] << " " << post_order[pu - 1] << endl;
			//cout << senority[post_order[pu - 1]]<< endl;
		}
		awkwardness(index_inorder[post_order[pu - 1]], root + 1, iu, pu - ro_num, pu - 1,sum);
	}
	if (iu-il-ro_num> 0) {
		//cout << "sub " << in_order.size() - ro_num << endl;
		if (senority[in_order[root]] < senority[post_order[pu- ro_num -1]]) { sum++; }
		awkwardness(index_inorder[post_order[pu - ro_num - 1]], il, root - 1, pl, pu - ro_num - 1,sum);
	}
	
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	long long n, s;
	long long sum = 0;
	cin >> n;
	//vector<long long> senority, post_order, in_order, r_inorder;
	//vector<pair<long long, long long>> in_order;
	senority.resize(n); in_order.resize(n); post_order.resize(n); index_inorder.resize(n);
	for (long long i = 0; i < n; i++) {
		cin >> senority[i];
	}
	for (long long i = 0; i < n; i++) {
		cin >> s;
		in_order[i] = s - 1;
		index_inorder[s - 1] = i;
	}


	for (long long i = 0; i < n; i++) {
		cin >> s;
		post_order[i] = s - 1;
	}
	//cout << r_inorder[0];
	awkwardness(index_inorder[post_order[n - 1]], 0, n - 1, 0, n - 1, sum);
	cout << sum;

	return 0;
}