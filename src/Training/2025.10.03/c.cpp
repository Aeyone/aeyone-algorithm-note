#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	priority_queue<int> qa, qb;
	for(auto &e : a){
		cin >> e;
		while(!(e & 1)){
			e >>= 1;
		}
		qa.push(e);
	}
	for(auto &e : b){
		cin >> e;
		while(!(e & 1)){
			e >>= 1;
		}
		qb.push(e);
	}
	while(qa.size() && qb.size()){
		auto A = qa.top();
		qa.pop();
		auto B = qb.top();
		qb.pop();
		while(B > A){
			qb.push(B >> 1);
			B = qb.top();
			qb.pop();
		}
		if(A > B){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}