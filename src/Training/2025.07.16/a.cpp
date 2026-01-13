#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	i64 k;
	cin >> n >> k;
	vector<i64> a(n);
	i64 sum = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], sum += a[i];

	sort(a.begin(), a.end());
	auto check = [&](i64 x)->i64{
		vector<i64> b = a;
		i64 s = sum;
		i64 res = max(0ll, b[0] - x);
		b[0] -= res;
		s -= res;
		while(b.size() > 1 && s > k){
			s -= (b.back() - b.front());
			b.pop_back();
			res ++;
		}
		return res;
	};
	i64 l = -1e9, r = min(k / n, a[0]);
	while(l + 18 <= r){
		i64 m1 = l + (r - l) / 3, m2 = l + (r - l) * 2 / 3;
		i64 ans1 = check(m1), ans2 = check(m2);
		if(ans1 > ans2)
			l = m1;
		if(ans1 < ans2)
			r = m2;
		if(ans1 == ans2)
			l = m1, r = m2;
	}
	i64 ans = 1e16;
	for(i64 i = l; i <= r; i ++)
		ans = min(ans, check(i));
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