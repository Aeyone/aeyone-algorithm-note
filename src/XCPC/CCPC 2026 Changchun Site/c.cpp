#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> b(n);
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
		b[i] --;
	}

	if (k * k > n) {
		int N = n / k + 1;
		vector<vector<int>> mp(k);
		vector<int> ans(k, n);
		for (int i = 0; i < n; i ++) {
			mp[i % k].push_back(b[i]);
		}
		for (int i = 0; i < k; i ++) {
			for (auto e : mp[i]) if (e < k)  {
				ans[(e - i + k) % k] --;
			}
		}
		cout << *min_element(ans.begin(), ans.end()) << '\n';
	} else {
		int res = INFLL;
		for (int st = 0; st < k; st ++) {
			int t = st, ans = n;
			for (int i = 0; i < n; i ++, t = (t + 1) % k) {
				if (b[i] == t) ans --;
			}
			res = min(res, ans);
		}
		cout << res << '\n';
	}
}
	
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}