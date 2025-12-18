//https://ac.nowcoder.com/acm/contest/view-submission?submissionId=79644103
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<array<int, 2>> bit(31);
	for(int i = 0; i <= 30; i ++){
		bit[i][0] ++;
	}
	int pre = 0;
	while(m > 0){
		int x = m & -m;
		m -= x;
		bit[__builtin_ffs(x) - 1][1] += (pre + 1);
		bit[__builtin_ffs(x) - 1][0] += x - (pre + 1);
		for(int i = 0; x >> i > 1; i ++){
			bit[i][0] += x / 2;
			bit[i][1] += x / 2;
		}
		for(int i = __builtin_ffs(x); i <= 30; i ++){
			bit[i][0] += x;
		}
		pre += x;
	}
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j <= 30; j ++){
			ans += bit[j][!(a[i] >> j & 1)] * (1 << j);
		}
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