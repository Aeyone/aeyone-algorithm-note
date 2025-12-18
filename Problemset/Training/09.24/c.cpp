#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string a, b;
	cin >> a >> b;
	map<char, int> mp;
	for(auto e : a){
		mp[e] ++;
	}
	int idx = 0;
	vector<char> getc(mp.size());
	for(auto &[c, e] : mp){
		getc[idx] = c;
		e = idx ++;
	}
	vector<int> vis(26);
	k = min(k, idx);
	i64 ans = 0;
	auto dfs = [&](auto &&self, int cur, int cnt){
		if(cnt == k){
			i64 res = 0;
			for(int l = 0, r = 0; r < n;){
				while(r < n && (a[r] == b[r] || vis[a[r] - 'a'])){
					r ++;
				}
				if(r > l){
					res += (i64)(r - l + 1) * (r - l) / 2;
					l = r;
				}else{
					l ++, r ++;
				}
			}
			ans = max(ans, res);
			return;
		}
		if(cur == idx){
			return;
		}
		self(self, cur + 1, cnt);
		vis[getc[cur] - 'a'] = true;
		self(self, cur + 1, cnt + 1);
		vis[getc[cur] - 'a'] = false;
	};
	dfs(dfs, 0, 0);
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
