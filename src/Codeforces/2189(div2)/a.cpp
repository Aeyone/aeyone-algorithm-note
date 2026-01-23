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
	int n, h, l;
	cin >> n >> h >> l;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	if (h < l) {
		swap(h, l);
	}
	sort(a.begin(), a.end());
	while (a.size() && a.back() > h) {
		a.pop_back();
	}
	int top = 0;
	for (auto e : a) {
		top += (e <= h && e > l);
	}
	while (a.size() && a.back() > l) {
		a.pop_back();
	}
	n = a.size();
	cout << min(n, top) + (n > top ? (n - top) / 2 : 0) << '\n';

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