#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i] >> b[i];

	auto check = [&](int x)->bool{
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(a[i] >= x - cnt - 1 && b[i] >= cnt)
				cnt ++;
		}
		return (cnt >= x);
	};

	int l = 1, r = n, ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}