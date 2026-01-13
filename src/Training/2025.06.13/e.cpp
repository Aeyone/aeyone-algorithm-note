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
	DSU g(2 * n);
	vector<int> vis(n);
	for(int i = 0; i < n; i ++){
		int a, b;
		cin >> a >> b;
		a --, b --;
		vis[a] ++, vis[b] ++;
		g.merge(a, b + n);//维护a和另外一个集合中的b的异色关系
		g.merge(a + n, b);
	}
	bool ok = true;
	for(int i = 0; i < n; i ++)
		ok &= (vis[i] == 2 && g.find(i) != g.find(i + n));

	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}