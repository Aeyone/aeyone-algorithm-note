#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 1e17;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<i64> dp(n + 1, -infll);
	vector<queue<int>> st(n + 1);
	dp[0] = 0;
	for(int i = 1; i <= n; i ++){
		dp[i] = dp[i - 1];
		st[a[i]].push(i);
		if(st[a[i]].size() == a[i]){
			if(dp[i] < dp[st[a[i]].front() - 1] + a[i])
				dp[i] = dp[st[a[i]].front() - 1] + a[i];
			st[a[i]].pop();
		}
	}
	cout << dp[n] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}