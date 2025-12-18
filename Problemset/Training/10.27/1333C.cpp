#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//前缀和计数
	int n;
	cin >> n;
	vector<i64> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	map<i64, i64> mp;
	i64 la = -1, ans = 0;
	for(int i = 0; i <= n; i ++){
		if(mp.find(pre[i]) != mp.end()){
			ans += (i64)(max(la, mp[pre[i]]) - la) * (n - i + 1);
			la = max(la, mp[pre[i]]);
		}
		mp[pre[i]] = i;
	}
	cout << (i64)n * (n + 1) / 2 - ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}