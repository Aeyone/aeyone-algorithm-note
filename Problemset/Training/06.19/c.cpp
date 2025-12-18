#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if(s[k - 1] != s[0] || k == n){
		cout << s[k - 1] << '\n';
		return;
	}
	string res;
	res += s[k - 1];
	map<char, int> mp;
	for(int i = k; i < n; i ++)
		mp[s[i]] ++;

	if(mp.size() == 1){
		int cnt = (mp[s[k]] + k - 1) / k;
		while(cnt)
			res += s[k], cnt --;
	}else{
		for(int i = k; i < n; i ++)
			res += s[i];
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}