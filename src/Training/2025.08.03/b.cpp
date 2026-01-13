#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<string> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	vector<array<array<int, 4>, 4>> pre(n + 1), suf(n + 1);
	for(int i = 0; i < n; i ++)
		pre[i].fill({-inf, -inf, -inf, -inf});

	for(int i = 0; i < n; i ++)
		suf[i].fill({inf, inf, inf, inf});

	map<char, int> mp;
	mp['R'] = 0, mp['B'] = 1, mp['G'] = 2, mp['Y'] = 3;
	for(int i = 1; i <= n; i ++){
		pre[i] = pre[i - 1];
		char e1 = a[i - 1][0], e2 = a[i - 1][1];
		if(mp[e1] > mp[e2])
			swap(e1, e2);
		pre[i][mp[e1]][mp[e2]] = i - 1;
	}
	for(int i = n - 2; i >= 0; i --){
		suf[i] = suf[i + 1];
		char e1 = a[i + 1][0], e2 = a[i + 1][1];
		if(mp[e1] > mp[e2])
			swap(e1, e2);
		suf[i][mp[e1]][mp[e2]] = i + 1;
	}
	while(q --){
		int x, y;
		cin >> x >> y;
		x --, y --;
		if(x > y)
			swap(x, y);
		int d = y - x;

		int cnt[4] = {};
		for(auto e : a[x])
			cnt[mp[e]] ++;
		for(auto e : a[y])
			cnt[mp[e]] ++;

		if(count(cnt, cnt + 4, 2) > 0){
			cout << d << '\n';
			continue;
		}
		int mn = inf;
		for(auto u : a[x]){
			for(auto v : a[y]){
				char t1 = u, t2 = v;
				if(mp[t1] > mp[t2])
					swap(t1, t2);
				mn = min(mn, suf[x][mp[t1]][mp[t2]]);
			}
		}
		if(mn < y){
			cout << d << '\n';
			continue;
		}
		int mx = -inf;
		for(auto u : a[x]){
			for(auto v : a[y]){
				char t1 = u, t2 = v;
				if(mp[t1] > mp[t2])
					swap(t1, t2);
				mx = max(mx, pre[x][mp[t1]][mp[t2]]);
			}
		}

		if(mx == -inf && mn == inf){
			cout << -1 << '\n';
		}else
			cout << min((x - mx) + (y - mx), (mn - x) + (mn - y)) << '\n';
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