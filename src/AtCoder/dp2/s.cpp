#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

string to_string(i64 num, int base){
	if(num == 0){
		return "0";
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector dp(2, vector(1 << n, vector(n, vector<i64>(n))));
	for (int mask = 1; mask < 1 << n; mask += 2) {
		bitset<6> bs(mask);
		int r = 0;
		while (r < n && bs[r] == 1) {
			r ++;
		}
		dp[0][mask][0][r - 1] = 1;
		cerr << "mask = " << to_string(mask, 2) << " l, r = " << 0 << ' ' << r - 1 << '\n';
	}

	auto getRange = [&](int mask)-> vector<array<int, 2>> {
		bitset<6> bs(mask);
		vector<array<int, 2>> res;
		for (int l = 0, r = 0; l < n; l = r) {
			while (r < n && bs[r] == bs[l]) {
				r ++;
			}
			if (bs[l]) {
				res.push_back({l, r - 1});
			}
		}
		return res;
	};

	for (int i = 1; i < n; i ++) {
		dp[i & 1].assign(1 << n, vector(n, vector<i64>(n)));
		for (int la = 0; la < 1 << n; la ++) {
			vector<array<int, 2>> laRange = getRange(la);
			for (int cur = 0; cur < 1 << n; cur ++) {
				for (auto [l, r] : getRange(cur)) for (auto [ql, qr] : laRange) {
					if (l > qr || ql > r) { // 没有交集
						continue;
					}
					// cerr << "l, r = " << l << ' ' << r << ' ';
					// cerr << "ql, qr = " << ql << ' ' << qr << ' ';
					// cerr << '\n';
					dp[i & 1][cur][l][r] = (dp[i & 1][cur][l][r] + dp[~i & 1][la][ql][qr]) % MOD;
				}
			}
		}
	}
	i64 ans = 0;
	for (int mask = 1 << (n - 1); mask < 1 << n; mask ++) {
		bitset<6> bs(mask);
		int l = n - 1;
		while (l >= 0 && bs[l]) {
			l --;
		}
		ans = (ans + dp[~n & 1][mask][l + 1][n - 1]) % MOD;
		cerr << "mask = " << to_string(mask, 2) << " l, r = " << l + 1 << ' ' << n - 1 << '\n';
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}