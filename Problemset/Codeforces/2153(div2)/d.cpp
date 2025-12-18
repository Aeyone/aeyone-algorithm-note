#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	i64 ans = INFLL;
	for(int c = 0; c < 4; c ++){
		vector<i64> f(n, INFLL);//f[i]为将(a[0]~a[i])分为若干个块的最小操作数
		f[1] = max(a[0], a[1]) - min(a[0], a[1]);
		f[2] = max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]});
		for(int i = 3; i < n; i ++){//任意长度>3的块都可以被拆分为若干个长度为2和3的块
			f[i] = min(
				f[i - 2] + max(a[i - 1], a[i]) - min(a[i - 1], a[i]),//块长度为2
				f[i - 3] + max({a[i - 2], a[i - 1], a[i]}) - min({a[i - 2], a[i - 1], a[i]})//块长度为3
			);
		}
		ans = min(ans, f[n - 1]);
		for(int i = 1; i < n; i ++){//将a数组循环左移
			swap(a[i - 1], a[i]);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}