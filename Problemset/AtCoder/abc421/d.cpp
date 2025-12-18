#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<i64> a(2), b(2);
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	map<char, int> mp;
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	mp['U'] = 0, mp['D'] = 1, mp['L'] = 2, mp['R'] = 3;

	i64 n, m, l;
	cin >> n >> m >> l;
	vector<pair<char, i64>> v1(m), v2(l);
	for(auto &[c, cnt] : v1)
		cin >> c >> cnt;
	for(auto &[c, cnt] : v2)
		cin >> c >> cnt;

	auto check = [&](char A, char B, i64 cnt)->int{
		char c[2] = {A, B};
		int mx = (a[0] >= b[0] ? 0 : 1);
		int mn = (a[0] < b[0] ? 0 : 1);

		if(mp[A] + mp[B] == 5 && a[1] == b[1])
			return (c[mx] == 'R' && abs(a[0] - b[0]) <= cnt);

		if(mp[A] + mp[B] == 1 && a[0] == b[0]){
			mx = (a[1] >= b[1] ? 0 : 1);
			mn = (a[1] < b[1] ? 0 : 1);
			return (c[mx] == 'D' && abs(a[1] - b[1]) <= cnt);
		}

		if(abs(a[0] - b[0]) == abs(a[1] - b[1]))
			return ((abs(a[0] - b[0]) <= cnt) && (c[mx] == 'R' || c[mn] == 'L'));
	};

	i64 T = 0, i = 0, j = 0, ans = 0;
	while(T < n){
		auto &[ca, cnta] = v1[i];
		auto &[cb, cntb] = v2[j];
		i64 mn = min(cnta, cntb);
		// cout << cnta << ' ' << cntb << ' ' << T << '\n';
		if(cnta < cntb)
			i ++, cntb -= cnta;
		else if(cnta > cntb)
			j ++, cnta -= cntb;
		else
			i ++, j ++;
		
		if(ca != cb)
			ans += check(ca, cb, mn);
		else if(a == b)
			ans += mn;

		T += mn;
		a[0] += mn * dx[mp[ca]], a[1] += mn * dy[mp[ca]];
		b[0] += mn * dx[mp[cb]], b[1] += mn * dy[mp[cb]];
		// cout << a[0] << ' ' << a[1] << '\n';
		// cout << b[0] << ' ' << b[1] << '\n';
	}
	cout << ans + (a == b) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}