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
	vector<int> a(n), b(n);
	for (auto &e : a) {
		cin >> e;
	}
	for (auto &e : b) {
		cin >> e;
	}

	set<int> st;
	bool ok = true;
	for (int i = n - k; i < k; i ++) {
		st.insert(a[i]);
	}
	for (int i = n - k; i < k; i ++) {
		if (b[i] != -1) {
			if (st.find(b[i]) != st.end()) {
				st.erase(st.find(b[i]));
			} else {
				ok = false;
			}
		}
	}
	for (int i = 0; i < n - k; i ++) {
		ok &= (b[i] == -1 || (b[i] == a[i]));
	}
	for (int i = k; i < n; i ++) {
		ok &= (b[i] == -1 || (b[i] == a[i]));
	}

	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
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