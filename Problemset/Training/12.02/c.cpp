#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
string lltos(i64 num, int base, int siz){
	if(num == 0){
		return string(siz, '0');
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	while(res.size() < siz){
		res += '0';
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<i64> dp(1 << n);
	dp[0] = 1;
	for(int mask = 1; mask < 1 << n; mask ++){
		char x = '#';
		for(int i = 0; i < n; i ++){
			if((mask >> i & 1) && s[i] != x){
				dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % MOD;
				x = s[i];
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
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