#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	ll n, x, l = 0, r = INFLL, cnt = 0, ans = 0;
	cin >> n >> x;
	vector<ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		r = min(r, a[i] + b[i]);
		ans += a[i] + b[i];
	}
	auto check = [&](ll m)->bool{
		for(int i=1;i<=n;i++){
			if(a[i]+b[i]<m) return 0;
			a[i]=max(a[i-1],m-b[i]);
			if(a[i]>m) return 0;
		}
		return 1;
	};
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			cnt = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	// cout<<cnt<<endl;
	cout << ans - n *cnt << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
//	cin >> _;
	while (_ --) {
		solve();
	}
}