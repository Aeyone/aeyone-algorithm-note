#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> rg(m);
	string s(2 * n, '.');
	for(auto &[r, l] : rg){
		cin >> l >> r;
		l --, r --;
		s[l] = '(';
	}
	sort(rg.begin(), rg.end(), greater<pair<int, int>>{});

	int now = 1e9;
	for(auto [r, l] : rg){
		if(r < now || l >= now){
			if(l > now)
				s[now] = '.';
			now = l;
		}else{
			s[l] = '.';
		}
	}
	// cin >> s;
	int cnt = n - count(s.begin(), s.end(), '(');
	for(int i = 0; i < 2 * n; i ++){
		if(s[i] != '.')
			continue;
		if(cnt > 0)
			s[i] = '(', cnt --;
		else
			s[i] = ')';
	}
	int sum = 0;
	bool ok = true;
	// for(auto e : s){
	// 	if(e == '(')
	// 		sum ++;
	// 	if(e == ')')
	// 		sum --;
	// 	ok &= (sum >= 0);
	// }
	// ok &= (sum == 0);

	if(ok)
		cout << s << '\n';
	else
		cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}