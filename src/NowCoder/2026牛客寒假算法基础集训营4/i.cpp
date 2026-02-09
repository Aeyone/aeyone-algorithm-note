#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	vector<char> v = {'#', 'W', 'G', 'B', 'P', 'Y', 'O'};

	auto check = [&](string s)->int{
		map<char, int> cnt;
		for (auto e : s) {
			cnt[e] ++;
		}
		int ans = 0;
		for (int i = 1; i <= 6; i ++) {
			for (int j = 1; j <= 6; j ++) {
				for (int k = 1; k <= 6; k ++) {
					map<char, int> mp;
					mp[v[i]] ++, mp[v[j]] ++, mp[v[k]] ++;
					for (auto [e, c] : mp) {
						if (c == 1) {
							ans += cnt[e] * 2;
						} else if (c == 2) {
							ans += cnt[e] * 3;
						} else if (c == 3) {
							ans += cnt[e] * 10;
						}
					}
				}
			}
		}
		return ans + cnt['#'] * 216;
	};
	pair<int, string> ans = {0, ""};
	for (int i = 0; i <= 6; i ++) {
		for (int j = 0; j <= 6; j ++) {
			for (int k = 0; k <= 6; k ++) {
				for (int l = 0; l <= 6; l ++) {
					for (int m = 0; m <= 6; m ++) {
						for (int n = 0; n <= 6; n ++) {
							string s = {v[i], v[j], v[k], v[l], v[m], v[n]};
							cmax(ans, {check(s), s});
						}
					}
				}
			}
		}
	}
	cout << ans.second << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}