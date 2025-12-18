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
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n, 0);
	DSU g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		cnt[u] ++, cnt[v] ++;
		g.merge(u, v);
	}
	if(m != n){
		cout << "No" << '\n';
		return;
	}
	bool ok = true;
	for(int i = 0; i < n; i ++)
		ok &= (cnt[i] == 2 && g.cmp(0, i));

	if(ok)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}