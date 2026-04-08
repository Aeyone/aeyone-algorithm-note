#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	ranges::reverse(s);
	auto run = [&](string s)-> int {
		int ans = 0;
		for (int l = 0, r = 0; l < n; l = r) {
			while (r < n && s[r] == s[l]) {
				r ++;
			}
			ans += (l > 0 && s[l] == '1');
		}
		return ans;
	};
	cout << run(s) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}