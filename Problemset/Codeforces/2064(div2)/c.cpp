#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<i64> b;
	i64 ans = 0;
	int idx = 0;
	while(idx < n && a[idx] > 0)
		ans += a[idx ++];

	i64 sum = (idx ? 0 : a[0]);
	for(int i = (idx ? idx : 1); i < n; i ++){
		if(a[i] * a[i - 1] < 0 && sum != 0)
			b.push_back(sum), sum = a[i];
		else
			sum += a[i];
	}
	if(sum != 0)
		b.push_back(sum);

	if(b.size() && b.back() < 0)
		ans += abs(b.back()), b.pop_back();

	n = b.size();
	if(n == 0){
		cout << ans << '\n';
		return;
	}
	vector<i64> s1(n), s2(n + 1);
	for(int i = 1; i < n; i ++)
		s1[i] = s1[i - 1] + max(0ll, b[i]);

	for(int i = n - 1; i >= 0; i --)
		s2[i] = s2[i + 1] - min(0ll, b[i]);
	
	i64 res = 0;
	for(int i = 0; i < n; i ++){
		res = max(s1[i] + s2[i], res);
	}
	cout << ans + res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}