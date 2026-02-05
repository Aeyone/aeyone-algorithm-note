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
	int n;
	cin >> n;
	vector<int> a(n), ne(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	map<int, int> mp;
	for (int i = n - 1; i >= 0; i --) {
		if (mp.find(a[i]) == mp.end()) {
			ne[i] = n;
		} else {
			ne[i] = mp[a[i]];
		}
		mp[a[i]] = i;
	}
	mp.clear();
	i64 cnt = 0, cur = 0, tot = 0;
	for (int i = 0; i < n; i ++) {
		if (!mp[a[i]]) {
			mp[a[i]] ++;
			cnt ++;
		}
		cur += 1ll * (n - i) * cnt;
		tot += (n - i);
	}
	i64 ans = cur;
	for (int i = 0; i < n; i ++) {
		cur -= 1ll * (ne[i] - i) * (n - i + (n - ne[i] + 1)) / 2;
		ans += cur;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}