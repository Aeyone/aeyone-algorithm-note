#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
struct DSU {
    vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool cmp(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
	int n;
	cin >> n;
	DSU g(n + 1);
	vector<int> a(n + 1);
	map<int, int> cnt;
	map<pair<int, int>, bool> vis;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		int x = min(a[i], i), y = max(a[i], i);
		g.merge(x, y);
		if(!vis[{x, y}])
			cnt[x] ++, cnt[y] ++, vis[{x, y}] = true;
	}
	int mx = 0, tmp = 0;
	for(int i = 1; i <= n; i ++){
		mx += (g.find(i) == i);
		tmp += (cnt[i] < 2);
	}
	cout << min(mx, mx - tmp / 2 + 1) << ' ' << mx << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}