#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() { // 数学推导转换为经典线段覆盖问题，这里用的另外一种方法，贪心做法只需要按照右端点，左端点都从小到大排序即可
	int n;
	cin >> n;
	using T = array<int, 3>;
	vector<T> a(n);
	for (auto &[sum, x, w] : a) {
		cin >> x >> w;
		sum = x + w;
	}
	sort(a.begin(), a.end());
	vector<int> siz(n), pre(n);
	for (int i = 1; i < n; i ++) {
		auto [_, x, w] = a[i];
		int idx = lower_bound(a.begin(), a.end(), array<int, 3>{x - w, INF, INF}) - a.begin();
		pre[i] = max(pre[i - 1], (idx != 0 ? pre[idx - 1] + 1 : 0));
	}
	cout << pre[n - 1] + 1 << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}