#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {
    long long int n, k, c, p;
    cin >> n >> k;
    vector<long long int> v_c, v_p;
    for (long long int i = 0; i < n; i++) {
        cin >> c >> p;
        v_c.push_back(c); v_p.push_back(p);
    }
    double left = 0.0, right = 1000000000.0;
    while (right - left > 0.000001) {
        double middle = (left + right) / 2;
        long long int time = 0;
        for (long long int i = 0; i < n; i++) {
            if ((long long int)(v_c[i] / middle) - v_p[i] > 0) {
                time += (long long int)(v_c[i] / middle) - v_p[i];
            }
        }
        if (time >= k) { left = middle; }
        else { right = middle; }
    }
    cout << setprecision(9) << (left + right) / 2;



    return 0;
}