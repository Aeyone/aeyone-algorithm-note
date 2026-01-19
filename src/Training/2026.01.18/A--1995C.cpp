#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 qmi(i64 a, i64 b, i64 p = INFLL){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	while(a.size() && a.back() == 1) {
		a.pop_back();
	}
	if (count(a.begin(), a.end(), 1)) {
		cout << -1 << '\n';
		return;
	}
	reverse(a.begin(), a.end());
	n = a.size();
	i64 pre = 0, ans = 0;
	for (int i = 1; i < n; i ++) {
		int k = 0;
		if (a[i - 1] < a[i]) {
			while (qmi(a[i - 1], (1 << (k + 1))) <= a[i]) {
				k ++;
			}
			pre = max(0ll, pre - k);
		} else {
			while (a[i - 1] > qmi(a[i], (1 << k))) {
				k ++;
			}
			pre += k;
		}
		ans += pre;
	}
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