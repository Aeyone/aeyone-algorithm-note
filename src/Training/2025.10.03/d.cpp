#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	vector<array<i64, 2>> cnt(31), sum(31);//cnt[j][x]为前缀异或中第j位出现x的次数，sum为下标和
	for(int i = 0; i <= 30; i ++){
		cnt[i][0] = 1;//考虑全选的情况，0初始个数全为1，下标和为0
	}
	i64 XOR = 0, ans = 0;
	for(int i = 1; i <= n; i ++){
		XOR ^= a[i];//维护前缀异或
		for(int j = 0; j <= 30; j ++){
			int x = (XOR >> j & 1);
			cnt[j][x] ++, sum[j][x] += i;
			ans = (ans + (1ll << j) * ((cnt[j][!x] * i - sum[j][!x]) % mod)) % mod;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}