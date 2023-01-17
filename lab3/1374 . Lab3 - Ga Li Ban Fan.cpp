#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define int long long

signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int t, n, c1000, c500, c100, c50, c10, c5, c1, c, r, change = 0;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int sum[8] = { 0 }, exchange[8] = { 0 };
		for (int j = 0; j < n; j++) {
			cin >> c >> c1000 >> c500 >> c100 >> c50 >> c10 >> c5 >> c1;
			
			sum[1] += c1000; sum[2] += c500; sum[3] += c100; sum[4] += c50; sum[5] += c10; sum[6] += c5; sum[7] += c1;
			change = 1000 * c1000 + 500 * c500 + 100 * c100 + 50 * c50 + 10 * c10 + 5 * c5 + c1 - c;
	
			//change = 675;
			if (change == 0) { continue; }
			else {
				r = change % 10;
				if (r >= 5) {
					exchange[6] += 1;
					exchange[7] += (r - 5);
				}
				else {
					exchange[7] += r;
				}
			}
			change /= 10;
	
			if (change == 0) { continue; }
			else {
				r = change % 10;
				if (r >= 5) {
					exchange[4] += 1;
					exchange[5] += (r - 5);
				}
				else {
					exchange[5] += r;
				}
			}
			change /= 10;
		
			if (change == 0) { continue; }
			else {
				r = change % 10;
				if (r >= 5) {
					exchange[2] += 1;
					exchange[3] += (r - 5);
				}
				else {
					exchange[3] += r;
				}
			}
			change /= 10;
			
			if (change == 0) { continue; }
			else {
				exchange[1] += change;
			}
		}
		
		sum[7] -= exchange[7];
		sum[6] += sum[7] / 5;
		sum[6] -= exchange[6];

		sum[5] += sum[6] / 2;
		sum[5] -= exchange[5];

		sum[4] += sum[5] / 5;
		sum[4] -= exchange[4];

		sum[3] += sum[4] / 2;
		sum[3] -= exchange[3];

		sum[2] += sum[3] / 5;
		sum[2] -= exchange[2];

		sum[1] += sum[2] / 2;
		sum[1] -= exchange[1];

		for (int j = 1; j < 8; j++) {
			if (sum[j] < 0) {
				cout << "No\n"; break;
			}
			if (j == 7) {
				cout << "Yes\n";
			}
		}
	
	}

	return 0;
}