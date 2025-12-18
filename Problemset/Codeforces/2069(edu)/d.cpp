#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> cnt(26), c1(26);
	for(auto e : s)
		cnt[e - 'a'] ++;

	for(int i = 0; i < n / 2; i ++)
		c1[s[i] - 'a'] ++;

	bool ok = true;
	for(int i = 0; i < 26; i ++)
		ok &= (c1[i] == (cnt[i] / 2));

	if(ok){
		string s1 = s.substr(0, n / 2), s2 = s.substr(n / 2, n / 2);
		reverse(s2.begin(), s2.end());
		int l = 0, r = n / 2 - 1;
		while(l < n / 2 && s1[l] == s2[l])
			l ++;
		while(r >= 0 && s1[r] == s2[r])
			r --;
		if(l < r)
			cout << r - l + 1 << '\n';
		else
			cout << 0 << '\n';
	}else{
		int l = 0, r = n - 1;
		while(l < n && r >= 0 && s[l] == s[r])
			cnt[s[l] - 'a'] -= 2, l ++, r --;

		fill(c1.begin(), c1.end(), 0);
		int t1 = r;
		while(t1 >= n / 2 && c1[s[t1] - 'a'] < cnt[s[t1] - 'a'] / 2)
			c1[s[t1] - 'a'] ++, t1 --;

		fill(c1.begin(), c1.end(), 0);
		int t2 = l;
		while(t2 < n / 2 && c1[s[t2] - 'a'] < cnt[s[t2] - 'a'] / 2)
			c1[s[t2] - 'a'] ++, t2 ++;

		cout << min(t1 - l + 1, r - t2 + 1) << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}