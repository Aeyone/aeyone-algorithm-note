#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//前缀和好题
	int n;
	cin >> n;
	vector<int> a(n + 1), pre(n + 1, -INF), suf(n + 2, -INF);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		pre[i] = max(pre[i - 1] - 1, a[i] - 1);
	}
	for(int i = n; i >= 1; i --){
		suf[i] = max(suf[i + 1] - 1, a[i] - 1);
	}
	int ans = -INF;
	for(int i = 2; i <= n - 1; i ++){
		ans = max(ans, a[i] + pre[i - 1] + suf[i + 1]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}