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
	vector<int> p(n + 1), u(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> p[i], u[p[i]] = i;

	DSU g(n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		if(i != p[i]){
			g.merge(p[i], i);
			cnt ++;
			u[p[i]] = u[i];
			swap(p[i], p[u[i]]);
			u[i] = i;
		}
	}
	cnt ++;
	bool ok = false;
	for(int i = 1; i <= n - 1; i ++)
		ok |= (g.cmp(i, i + 1));

	cout << cnt - ok * 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}