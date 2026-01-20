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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	string s;
	cin >> s;
	using T = pair<int, int>;
	priority_queue<T, vector<T>, greater<T>> heap1, heap2;
	for (int i = 0; i < n; i ++) {
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		if (it != b.end()) {
			heap1.push({*it - a[i], i});//后
		}
		if (it != b.begin()) {
			heap2.push({a[i] - *(-- it), i});//前
		}
	}
	vector<int> vis(n, 1);
	int mn = 0, mx = 0, cur = 0, ans = n;
	for (int i = 0; i < k; i ++) {
		cur += (s[i] == 'L' ? -1 : 1);
		mn = min(mn, cur);
		mx = max(mx, cur);
		while (heap1.size() && heap1.top().first <= mx) {
			auto [_, u] = heap1.top();
			ans -= vis[u];
			vis[u] = false;
			heap1.pop();
		}
		while (heap2.size() && heap2.top().first <= abs(mn)) {
			auto [_, u] = heap2.top();
			ans -= vis[u];
			vis[u] = false;
			heap2.pop();
		}
		cout << ans << ' ';
	}
	cout << '\n';
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