#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	if(s == t) {
		cout << 0 << '\n';
		return;
	}
	vector<int> f(26, -1);
	bool ok = true;
	for(int l = 0, r = 0; l < n; l = r) {
		int u = t[l] - 'a';
		while(r < n && t[l] == t[r]) {
			r ++;
		}
		for(int i = l; i < r; i ++) {
			int v = s[i] - 'a';
			if(f[v] == -1) {
				f[v] = u;
			}
			ok &= (f[v] == u);
		}
	}
	if(!ok) {
		cout << -1 << '\n';
		return;
	}
	string ss = s, tt = t;
	sort(ss.begin(), ss.end());
	ss.erase(unique(ss.begin(), ss.end()), ss.end());
	sort(tt.begin(), tt.end());
	tt.erase(unique(tt.begin(), tt.end()), tt.end());

	if(ss.size() == tt.size() && ss.size() == 26) {
		cout << -1 << '\n';
		return;
	}
	vector<int> in(26);
	int ans = 0;
	for(int i = 0; i < 26; i ++) {
		if(f[i] != -1) {
			ans += (f[i] != i);
			in[f[i]] ++;
		}
	}
	queue<int> q;
	vector<int> vis(26);
	for(int i = 0; i < 26; i ++) {
		if(in[i] == 0 && f[i] != -1) {
			vis[i] = true;
			q.push(i);
		}
	}
	while(q.size()) {
		auto u = q.front();
		q.pop();
		int v = f[u];
		vis[v] = true;
		in[v] --;
		if(in[v] == 0 && f[v] != -1) {
			q.push(v);
		}
	}
	for(int i = 0; i < 26; i ++) {
		if(in[i] <= 0 || f[i] == i) {
			continue;
		}
		bool ok = (!vis[i]);
		in[i] --;
		for(int v = f[i]; v != i; v = f[v]) {
			ok &= (!vis[v]);
			in[v] --;
		}
		ans += ok;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}