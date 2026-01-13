#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {//还不错的一道计数题
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, i64> mp, ans;
	for(auto &e : a){
		cin >> e;
		mp[e] ++;
	}
	sort(a.begin(), a.end(), greater<int>{});
	for(int i = 2; i <= 1000; i ++){
		int e = i * i;
		for(int k = 0; k < n && a[k] > i; k ++){
			if(a[k] % e != 0){
				continue;
			}
			ans[a[k] / i] += mp[a[k] / e];
		}
	}
	i64 res = 0;
	for(auto [_, e] : mp){
		res += (e * (e - 1) * (e - 2));
	}
	for(int i = 0; i < n; i ++){
		res += ans[a[i]];
	}
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}