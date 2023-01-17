#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;


long long mode(long long int base, long long n) {
	
	if (n == 0) {
		return 1;
	}
	else {
		long long sum = 1;
		base %= 1000000007;
		while (n > 0) {
			if (n % 2 == 1) {
				sum *= base;
				sum %= 1000000007;
				n--;
			}
			else {
				base *= base;
				base %= 1000000007;
				n /= 2;
			}
		}
		return sum;
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	long long int a, b, n, x;
	cin >> a >> b >> n;
	x = b / (1 - a);
	long long int i, temp = 1, last_i = 1, d1 = 0, d2, sum = 0;
	//cout<<mode(a, b);
	for (long long int j = 0; j < n; j++) {
		cin >> i; 
		temp =mode(a, i - 1);
		sum = (temp - (temp * x) % 1000000007 + x) % 1000000007;
		if (sum < 0) {
			cout << sum + 1000000007 << "\n";
		}
		else {
			cout << sum << "\n";
		}
	}


	return 0;
}