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
    
    bool merge(int x, int y) {//将y合并至x中
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
	vector<int> siz(n);//边的个数
	DSU g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		if(g.find(u) != g.find(v)){
			siz[g.find(u)] += siz[g.find(v)] + 1;
		}else{
			siz[g.find(u)] ++;
		}
		g.merge(u, v);
	}

	int cey = 0, block = 0;
	for(int i = 0; i < n; i ++){
		if(g.find(i) == i){
			block ++;
			cey += siz[i] - (g.size(i) - 1);
		}
	}
	cout << cey + block - 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}