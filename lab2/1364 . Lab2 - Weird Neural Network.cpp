#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class neuron {
public:
	int c;
	neuron* output = NULL, * input1 = NULL, * input2 = NULL;
	neuron(int c) :c(c) {}
};

long long int output(neuron* a) {
	if (a->input1 == NULL && a->input2 == NULL) {
		return a->c;
	}
	else {
		return(a->c * ((output(a->input1) + output(a->input2)) % 1000000007)) % 1000000007;
	}
}

neuron* root = NULL;

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int n, c, o;
	vector<neuron*> v; 
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c;
		neuron* my_neuron = new neuron(c);
		v[i]=my_neuron;
	}
	for (int i = 1; i < n ; i++) {
		cin >> o;
		if (v[o - 1]->input1 == NULL) {
			v[o - 1]->input1 = v[i];
		}
		else {
			v[o - 1]->input2 = v[i];
		}
	}

	cout << output(v[0]);


	return 0;
}