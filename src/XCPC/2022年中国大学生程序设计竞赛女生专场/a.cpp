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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int idx = max_element(a.begin(), a.end()) - a.begin();
	vector<int> mx(n);
	mx[0] = a[0];
	for (int i = 1; i < n; i ++) {
		mx[i] = max(mx[i - 1], a[i]);
	}
	for (int i = 0; i < idx; i ++) {
		int cnt = upper_bound(mx.begin(), mx.end(), a[i]) - mx.begin();
		if (cnt - i >= k) {
			idx = i;
			break;
		}
	}
	cout << idx + 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}