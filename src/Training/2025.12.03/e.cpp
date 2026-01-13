#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	int ans = 2 * n - 1;
	auto check = [&](int a, int b, int c)->bool{
		return 1ll * (c - b) * (b - a) < 0;
	};
	for(int i = 0; i < n - 2; i ++){
		ans += check(a[i], a[i + 1], a[i + 2]);
		if(i + 3 < n){
			bool ok = true;
			ok &= check(a[i], a[i + 1], a[i + 2]);
			ok &= check(a[i], a[i + 1], a[i + 3]);
			ok &= check(a[i], a[i + 2], a[i + 3]);
			ok &= check(a[i + 1], a[i + 2], a[i + 3]);
			ans += ok;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}