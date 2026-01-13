#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	if(n <= 2){
		cout << 1 + count(a.begin(), a.end(), 0) << '\n';
		return;
	}
	map<int, i64> mp, ne;
	mp[a[0]] ++, ne[a[1]] ++;
	for(int i = 2; i < n; i ++){
		map<int, i64> cur;
		cur[a[i]] ++;
		// cerr << mp.size() << '\n';
		for(auto [e, c] : mp){
			cur[(e + a[i]) % m] += c;
		}
		for(auto [e, c] : ne){
			mp[e] += c;
		}
		ne = cur;
	}
	cout << 1 + mp[0] + ne[0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}