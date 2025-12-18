#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	cout << a.size() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}