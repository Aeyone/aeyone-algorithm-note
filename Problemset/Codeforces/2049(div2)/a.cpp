#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	int pre = 0, suf = 0, l = 0, r = n - 1;
	while(l < n && a[l] == 0)
		l ++, pre ++;
	while(r >= 0 && a[r] == 0)
		r --, suf ++;
	if(count(a.begin(), a.end(), 0) == n){
		cout << 0 << '\n';
	}else if(count(a.begin(), a.end(), 0) == pre + suf){
		cout << 1 << '\n';
	}else
		cout << 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}