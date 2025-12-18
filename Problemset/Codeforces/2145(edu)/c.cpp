#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ca = count(s.begin(), s.end(), 'a');
	int cb = count(s.begin(), s.end(), 'b');
	if(ca == cb){
		cout << 0 << '\n';
		return;
	}
	s = "X" + s;
	vector<int> suf(n + 2);
	map<int, set<int>> mp;
	for(int i = n; i >= 1; i --){
		suf[i] = suf[i + 1] + (s[i] == 'a') - (s[i] == 'b');
		mp[suf[i]].insert(i);
	}
	mp[0].insert(n + 1);
	int cur = 0, ans = *mp[0].begin() - 1;
	for(int i = 1; i <= n; i ++){
		mp[suf[i]].erase(i);
		if(mp[suf[i]].size() == 0){
			mp.erase(suf[i]);
		}
		cur = cur + (s[i] == 'a') - (s[i] == 'b');
		if(mp.find(-cur) == mp.end()){
			continue;
		}
		ans = min(ans, *mp[-cur].begin() - i - 1);
	}
	cout << (ans == n ? -1 : ans) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}