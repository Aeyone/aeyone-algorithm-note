#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	vector<vector<int>> tot(n + 1, vector<int>(101));
	vector<vector<int>> pre(n + 1, vector<int>(101));
	vector<vector<int>> pre2(n + 1, vector<int>(101));
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pre[i] = pre[i - 1];
		pre2[i] = pre2[i - 1];
		tot[i] = tot[i - 1];
		pre[i][a[i]] += i;
		pre2[i][a[i]] += i * i;
		tot[i][a[i]] ++;
	}
	while(q --){
		int l, r;
		cin >> l >> r;
		int X = r - l + 1 + 1;//len + 1
		int ans = 0;
		for(int num = 1; num <= 100; num ++){
			int sum = pre[r][num] - pre[l - 1][num];
			int sum2 = pre2[r][num] - pre2[l - 1][num];
			int cnt = tot[r][num] - tot[l - 1][num];
			if(cnt == 0){
				continue;
			}
			int ans2 = sum2 - 2ll * (l - 1) * sum + 1ll * cnt * (l - 1) * (l - 1);
			ans += num * (X * (sum - 1ll * cnt * (l - 1)) - ans2);
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}