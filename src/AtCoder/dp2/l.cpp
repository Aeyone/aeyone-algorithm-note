#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct Info{
    i64 max = -INFLL;
};

Info operator+(const Info &l, const Info &r){
    Info res;
    res.max = max(l.max, r.max);
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
            info[p] = Info();
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            up(p);
        }
    }

    void modify(int p, int l, int r, int X, i64 val){
        if (X > r || X < l){
            return;
        }
        if (l == r){
            info[p].max = val;
        }else{
            int mid = (l + r) / 2;
            modify(2 * p, l, mid, X, val);
            modify(2 * p + 1, mid + 1, r, X, val);
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
    void modify(int X, i64 val){
        modify(1, 1, n, X, val);
    }
    Info query(int L, int R){
    	if (L > R) {
    		return Info();
    	}
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n;
	cin >> n;
	vector a(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	SegmentTree st(n);
	st.modify(1, 0);
	for (int i = 2; i <= n; i ++) {
		int sum = 0;
		for (int j = i; j >= 1; j --) {
			sum += a[i][j] * 2;
			st.modify(j, st.query(1, j).max + sum);
		}
	}
	cout << st.query(1, n).max << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}