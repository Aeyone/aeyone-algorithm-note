#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

struct DSU {
    vector<int> f, siz, col;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        col.assign(n, 0);
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
        col[x] += col[y];//颜色为黑色的数量
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
    int color(int x){
    	return col[find(x)];
    }
    void modify(int x, int c){
    	col[find(x)] += c;
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	vector<int> col(n);
	while(q --){
		int c, u;
		cin >> c >> u;
		u --;
		if(c == 1){
			int v;
			cin >> v;
			v --;
			dsu.merge(u, v);
		}
		if(c == 2){
			dsu.modify(u, (col[u] ? -1 : 1));
			col[u] = !col[u];
		}
		if(c == 3){
			if(dsu.color(u) > 0){
				cout << "Yes" << '\n';
			}else{
				cout << "No" << '\n';
			}
		}
	}
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