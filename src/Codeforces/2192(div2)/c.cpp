#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	int n, h, k;
	cin >> n >> h >> k;
	vector<i64> a(n + 1);
	i64 sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}

	i64 cnt = h / sum, r = h % sum;
	if (r == 0) {
		r = sum, cnt --;
	}
	vector<i64> pre(n + 1), prem(n + 1, INFLL), sufm(n + 2);

	for (int i = n; i >= 1; i --) {
		sufm[i] = max(sufm[i + 1], a[i]);
	}
	for (int i = 1; i <= n; i ++) {
		prem[i] = min(prem[i - 1], a[i]);
		pre[i] = pre[i - 1] + a[i];
	}

	int need = 0;
	for (int i = 1; i <= n; i ++) {
		if (pre[i] + max(0ll, sufm[i + 1] - prem[i]) >= r) {
			need = i;
			break;
		}
	}
	cout << cnt * (n + k) + need << '\n';
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