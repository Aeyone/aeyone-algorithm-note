#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), c(n + 1);
	vector<i64> dp(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	i64 sum = 0;
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
		dp[i] = c[i];
		sum += c[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j < i; j ++){
			if(a[i] >= a[j]){
				dp[i] = max(dp[i], dp[j] + c[i]);
			}
		}
	}
	i64 mn = INFLL;
	for(int i = 1; i <= n; i ++){
		mn = min(mn, sum - dp[i]);
	}
	cout << mn << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}