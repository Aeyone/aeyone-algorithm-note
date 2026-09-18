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
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> v1, v2;
	for (int i = 0; i < n - 2; i ++) {
		if (a[i] & 1) {
			v1.push_back(a[i]);
		} else {
			v2.push_back(a[i]);
		}
	}
	swap(a[0], a[n - 2]);
	i64 sum = 0;
	for (int i = 1; i < n - 1; i ++) {
		if (a[i - 1] & 1) {
			if (!v2.size()) {
				v2.push_back(v1.back());
				v1.pop_back();
			}
			a[i] = v2.back();
			v2.pop_back();
		} else {
			if (!v1.size()) {
				v1.push_back(v2.back());
				v2.pop_back();
			}
			a[i] = v1.back();
			v1.pop_back();
		}
	}
	for (int i = 1; i < n; i ++) {
		sum += (a[i] + a[i - 1]) / 2;
	}
	cout << sum << '\n';
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