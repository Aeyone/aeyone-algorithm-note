#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 2), k(m + 1), l(n + 1), r(n + 1), stk;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i ++) {
		cin >> k[i];
	}

	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n + 1; i ++) {
		while (stk.size() && a[i] < a[stk.back()]) {
			r[stk.back()] = i - 1;
			stk.pop_back();
		}
		stk.push_back(i);
	}
	stk.clear();
	for (int i = n; i >= 0; i --) {
		while (stk.size() && a[i] <= a[stk.back()]) {
			l[stk.back()] = i + 1;
			stk.pop_back();
		}
		stk.push_back(i);
	}
	i64 sum = 0, ans = 0;
	using T = array<int, 2>;
	priority_queue<T, vector<T>, greater<T>> heap;

	vector<i64> w(n + 1);
	for (int i = 1; i <= n; i ++) {
		heap.push({a[i] - 1, i});
		ans = (ans + 1ll * i * (n - i + 1) % MOD * qmi(a[i], MOD - 2) % MOD) % MOD;
		w[i] = 1ll * (i - l[i] + 1) * (r[i] - i + 1) % MOD;
		sum = (sum + w[i] * qmi(a[i], MOD - 2) % MOD) % MOD;
	}
	for (int i = 1; i <= m; i ++) {
		vector<int> v;
		while (heap.size() && heap.top()[0] < k[i]) {
			auto [x, j] = heap.top();
			heap.pop();
			v.push_back(j);
			int d = x - k[i - 1];
			ans = (ans + w[j] * qmi(a[j], MOD - 2) % MOD * d % MOD) % MOD;
			sum = (sum + MOD - w[j] * qmi(a[j], MOD - 2) % MOD) % MOD;
		}
		ans = (ans + (k[i] - k[i - 1]) * sum % MOD) % MOD;
		for (auto j : v) {
			int d = k[i] - a[j] + 1;
			ans = (ans + w[j] * d % MOD) % MOD; 
			sum = (sum + w[j] % MOD) % MOD;
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}