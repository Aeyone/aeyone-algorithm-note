#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {//二分好题
	int n;
	cin >> n;
	vector<int> a(n);
	int mn = inf;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	auto check = [&](int x)->bool{
		vector<int> add(n);
		bool ok = true;
		for(int i = n - 1; i >= 2; i --){
			ok &= (a[i] + add[i] >= x);
			if(!ok)
				return false;
			int cnt = min(a[i] / 3, (a[i] + add[i] - x) / 3);
			add[i - 1] += cnt;
			add[i - 2] += 2 * cnt;
		}
		return (ok && a[0] + add[0] >= x && a[1] + add[1] >= x);
	};
	int l = mn, r = inf, ans = mn;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid, l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}