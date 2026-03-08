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
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> b(min(n + 1, m));
	int idx = 1;
	for (int t = 1; t <= l; t ++) {
		b.back() ++;
		sort(b.begin(), b.end(), greater<int>{});
		if (idx <= n &&  t == a[idx]) {
			b.front() = 0;
			sort(b.begin(), b.end(), greater<int>{});
			idx ++;
		}
		if (b.size() > n - idx + 2) {
			b.pop_back();
		}
	}
	cout << b[0] << '\n';
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