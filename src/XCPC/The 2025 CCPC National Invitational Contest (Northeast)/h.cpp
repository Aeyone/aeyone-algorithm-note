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
	int n;
	cin >> n;
	using T = array<int, 3>;
	vector<T> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i][1];
	}
	for (int i = 0; i < n; i ++) {
		cin >> a[i][0];
	}
	vector<int> c(n);
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i ++) {
		a[i][2] = c[a[i][1] - 1];
	}

	sort(a.begin(), a.end(), greater<T>{});

	auto check = [&](int x)->bool {
		vector<int> back(n), ok(n);
		for (int i = 0; i < n; i ++) {
			back[i] = x / a[i][2];
		}
		int tot = 0, cnt = 0;
		for (int l = 0, r = 0; l < n; l ++) {
			if (r == l) {
				r = (r + 1) % n;
			}
			int cur = a[l][0];
			while (r != l && back[r] <= cur) {
				cur -= back[r];
				back[r] = 0;
				r = (r + 1) % n;
			}
			if (r != l) {
				back[r] -= cur;
				ok[l] = true;
			} else {
				ok[l] = (cur == 0);
				break;
			}
		}

		return count(ok.begin(), ok.end(), 1) == n;
	};

	int l = 0, r = INFLL, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	// cout << check(6) << '\n';
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