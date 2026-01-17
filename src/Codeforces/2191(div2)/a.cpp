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
	vector<int> a(n);
	set<int> st1, st2;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i & 1) {
			st1.insert(a[i]);
		} else {
			st2.insert(a[i]);
		}
	}
	sort(a.begin(), a.end());
	bool ok1 = true, ok2 = true;
	for (int i = 0; i < n; i ++) {
		if (i & 1) {
			ok1 &= (st1.find(a[i]) != st1.end());
		} else {
			ok1 &= (st2.find(a[i]) != st2.end());
		}
	}
	for (int i = 0; i < n; i ++) {
		if (i & 1) {
			ok2 &= (st2.find(a[i]) != st2.end());
		} else {
			ok2 &= (st1.find(a[i]) != st1.end());
		}
	}
	if (ok1 || ok2) {
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