#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

struct Info{
    i64 sum = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.sum = l.sum + r.sum;
    return res;
}
 
struct SegmentTree{
    int n;
    vector<Info> info;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }

    void init(int _n){
        n = _n;
        info.assign(n << 2, Info());
        build(1, 1, n);
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r){
        if (l == r){
            info[p].sum = 1;
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }

    void modify(int p, int l, int r, int L, int R, i64 val){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){
            info[p].sum += val;
        }else{
            int mid = (l + r) / 2;
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            up(p);
        }
    }

    Info query(int p, int l, int r, int L, int R){
        if(L > r || R < l){
            return Info();
        }
        Info res;
        if(L <= l && r <= R){
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, i64 val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<array<int, 2>> seg(n - 1);
	for(int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
		seg[i] = {u, v};
	}
	vector<int> dfn(n), siz(n, 1);
	int T = 1;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		dfn[u] = T ++;
		for(auto v : g[u]) if(v != fa) {
			self(self, v, u);
			siz[u] += siz[v];
		}
	};
	dfs(dfs, 0, -1);
	vector<int> edge(n - 1);
	for(int i = 0; i < n - 1; i ++) {
		if(dfn[seg[i][0]] > dfn[seg[i][1]]) {
			edge[i] = seg[i][0];
		}else{
			edge[i] = seg[i][1];
		}
	}
	SegmentTree st(n);
	int q;
	cin >> q;
	while(q --) {
		int c;
		cin >> c;
		if(c == 1) {
			int x, w;
			cin >> x >> w;
			x --;
			st.modify(dfn[x], dfn[x], w);
		}else{
			int y;
			cin >> y;
			y --;
			int u = edge[y];
			i64 sum = st.query(1, n).sum;
			i64 subsum = st.query(dfn[u], dfn[u] + siz[u] - 1).sum;
			cout << abs(sum - 2 * subsum) << '\n';
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