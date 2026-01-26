#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct Info{
    i64 sum = 0;
};

struct Lazy{
    i64 add = 0;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.sum = l.sum + r.sum;
    return res;
}
 
struct SegmentTree{
    int n;
    vector<Info> info;
    vector<Lazy> lazy;
 
    SegmentTree() {}
    SegmentTree(int _n) {
        init(_n);
    }

    void init(int _n){
        n = _n;
        info.assign(n << 2, Info());
        lazy.assign(n << 2, Lazy());
        build(1, 1, n);
    }

    void apply(int p, i64 val, int siz){
        info[p].sum += val * siz;
        lazy[p].add += val;
    }

    void down(int p, int sizL, int sizR){
        if (lazy[p].add != 0){
            apply(2 * p, lazy[p].add, sizL);
            apply(2 * p + 1, lazy[p].add, sizR);
            lazy[p].add = 0;
        }
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void build(int p, int l, int r){
        if (l == r){
            info[p] = Info(0);
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
            apply(p, val, r - l + 1);
        }else{
            int mid = (l + r) / 2;
            down(p, mid - l + 1, r - mid);
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
            down(p, mid - l + 1, r - mid);
            res = query(2 * p, l, mid, L, R) + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int L, int R, i64 val){
        modify(1, 1, n, L, R, val);
    }
    Info query(int X){
        return query(1, 1, n, max(1ll, X), max(1ll, X));
    }
};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> dfn(n), siz(n), deep(n), d(n);
	int T = 0;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		siz[dfn[u]] = 1;
		for (auto v : g[u]) if (v != fa) {
			dfn[v] = T ++;
			deep[dfn[v]] = deep[dfn[u]] + 1;
			self(self, v, u);
			d[dfn[u]] = max(d[dfn[u]], d[dfn[v]]);
			siz[dfn[u]] += siz[dfn[v]];
		}
		d[dfn[u]] += 1;
	};
	dfn[0] = T ++;
	deep[0] = 0;
	dfs(dfs, 0, -1);

	int summ = 0, cntt = 0;
	multiset<int> st;
	SegmentTree cnt(n + 1), sum(n + 1);

	auto add = [&](int i)->void{
		cnt.modify(1, deep[i] + 1, 1);
		cntt ++;

		sum.modify(1, deep[i], deep[i]);
		summ += deep[i];
		st.insert(deep[i]);
	};

	auto del = [&](int i)->void{
		cnt.modify(1, deep[i] + 1, -1);
		cntt --;

		sum.modify(1, deep[i], -deep[i]);
		summ -= deep[i];
		st.erase(st.find(deep[i]));
	};

	int l = -1, r = n, ans = 0;
	for (int i = 1; i < n; i ++) {
		int L = i - 1, R = i + siz[i];
		while (l < L) {
			add(++ l);
		}
		while (r > R) {
			add(-- r);
		}
		while (r < R) {
			del(r ++);
		}
		int mx = *--st.end();

		int cnt2 = cnt.query(mx - d[i] + 1).sum;// > max - d
		int sum2 = sum.query(mx - d[i]).sum;
		ans += sum2 + cnt2 * d[i] + (cntt - cnt2) * mx;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}