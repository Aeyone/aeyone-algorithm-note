#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	int k;
	cin >> s >> k;
	bool ok = true;
	int l = 0, r = s.size() - 1;
	while(l < r)
		ok &= (s[l ++] == s[r --]);

	if(ok){
		cout << s << ' ' << 0 << '\n';
		return;
	}
	int cnt = 1;
	while(cnt <= k){
		string s1 = s;
		while(s1.back() == '0')
			s1.pop_back();

		reverse(s1.begin(), s1.end());
		i64 x = stoll(s) + stoll(s1);
		s = to_string(x);

		bool ok = true;
		int l = 0, r = s.size() - 1;
		while(l < r)
			ok &= (s[l ++] == s[r --]);

		if(ok)
			break;
		cnt ++;
	}
	cout << s << ' ';
	if(cnt > k)
		cout << -1 << '\n';
	else
		cout << cnt << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}