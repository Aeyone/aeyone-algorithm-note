#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {//又一个前缀和好题
	int n;
	cin >> n;
	vector<int> a(n + 1), pre(n + 1), suf(n + 2);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pre[i] = max(pre[i - 1], a[i] + n - i);
	}
	for(int i = n; i >= 1; i --){
		suf[i] = max(suf[i + 1], a[i] + i - 1);
	}
	int ans = inf;
	for(int i = 1; i <= n; i ++){
		ans = min(ans, max({a[i], pre[i - 1], suf[i + 1]}));
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}