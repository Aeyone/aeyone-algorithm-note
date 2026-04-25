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
	int n, m;
	cin >> n >> m;
	priority_queue<int> h1, h2;
	vector<int> a(n), x(m);
	i64 sum = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i & 1) {
			h2.push(a[i]);
		} else {
			h1.push(a[i]);
		}
		sum += a[i];
	}
	bool ok1 = false, ok2 = false;
	for (int i = 0; i < m; i ++) {
		cin >> x[i];
		if (x[i] & 1) {
			if (!h1.size() || (ok1 && h1.top() < 0)) {
				continue;
			}
			sum -= h1.top();
			h1.pop();
			ok1 = true;
		} else {
			if (!h2.size() || (ok2 && h2.top() < 0)) {
				continue;
			}
			sum -= h2.top();
			h2.pop();
			ok2 = true;
		}
	}
	cout << sum << '\n';

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