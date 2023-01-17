#include<iostream>
#include<set>
using namespace std;


int main() {


    cin.tie(0);
    cin.sync_with_stdio(0);

	cin.tie(0); cin.sync_with_stdio(0);
 	long long int n, t, w, sum = 0;
 	multiset<long long int> s;
 	//multiset<long long int> ans;//, s_unvisited, s_unvisited_it;
 	//set<int> s_unvisited_it;
 	cin >> n >> t;
 	for (int i = 0; i < n; i++) {
  	cin >> w;  s.insert(w); //s_unvisited.insert(w);
	}
    multiset<long long int>::iterator end_1 = s.end();
    int time = 0;
    int i = 0;
    for (auto iter = s.begin();iter!=end_1;){
        i = *iter;
        long long int temp = 100000000;
        for ( auto it = ++iter; it != end_1; it++) {
            //cout<<*itr1<<" "<<*itr2<<" "<<(t - *itr1 - *itr2)<<endl;;
            int k = t - i - *it;

            if (temp == *it) continue;
            else if (k >= *it && k >= i){
                int a = 0;
                if(k == i) a++;
                if(k == *it) a++;
                if(s.count(k) - a) {
                    time++;
                }
            }
            temp = *it;
        }
        --iter;
        iter = s.upper_bound(i);
    }

    if (time == 0)cout << "FeiDooDoo_Zuo_Wei_Men";
    else cout << time;

    //system("pause");
    return 0;
}