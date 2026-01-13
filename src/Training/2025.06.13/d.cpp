#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
i64 bit[10], sum[N];

void init(int m){
	for(int k = 1; k <= m; k ++){
		i64 backup = bit[9];
		for(int i = 9; i > 0; i --){
			bit[i] = bit[i - 1];
			bit[i - 1] = 0;
		}
		if(backup){
			bit[0] = (bit[0] + backup) % mod;
			bit[1] = (bit[1] + backup) % mod;
		}
		i64 cnt = 0;
		for(int i = 0; i <= 9; i ++)
			cnt = (cnt + bit[i]) % mod;
		sum[k] = cnt;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	string s = to_string(n);
	vector<int> b(10);
	for(int i = 0; i < s.size(); i ++)
		b[s[i] -'0'] ++;
	
	i64 ans = 0;
	for(int i = 0; i <= 9; i ++)
		ans = (ans + (b[i] * sum[m + i]) % mod) % mod;

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	bit[0] = 1;
	init(200010);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}