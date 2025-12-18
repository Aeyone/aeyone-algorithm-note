#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

struct Info{
    i64 mn;
    Info(i64 s = inf) : mn(s) {}
};
 
struct SegmentTree{
    int n;
    vector<Info> info;
 
    SegmentTree() {}
    SegmentTree(int _n, vector<int> &arr) {
        init(_n, arr);
    }

    void init(int _n, vector<int> &arr){
        n = _n;
        info.assign(n << 2, Info());
        build(1, 1, n, arr);
    }
    void build(int p, int l, int r, vector<int> &arr){
        if (l == r){
            info[p].mn = arr[l - 1];
        }else{
            int mid = (l + r) / 2;
            build(2 * p, l, mid, arr);
            build(2 * p + 1, mid + 1, r, arr);
            info[p].mn = min(info[2 * p].mn, info[2 * p + 1].mn);
        }
    }
    void modify(int p, int l, int r, int L, int R, i64 val){
        if (L > r || R < l)
            return;
        if (L <= l && r <= R){
            info[p].mn += val;
        }else{
            int mid = (l + r) / 2;
            modify(2 * p, l, mid, L, R, val);
            modify(2 * p + 1, mid + 1, r, L, R, val);
            info[p].mn = min(info[2 * p].mn, info[2 * p + 1].mn);
        }
    }
    i64 query(int p, int l, int r, int L, int R){
        if(L > r || R < l)
            return inf;

        i64 res = inf;
        if(L <= l && r <= R){
            res = info[p].mn;
        }else{
            int mid = (l + r) / 2;
            res = min(res, query(2 * p, l, mid, L, R));
            res = min(res, query(2 * p + 1, mid + 1, r, L, R));
        }
        return res;
    }
    //0-based
    void modify(int X, i64 val){
        modify(1, 1, n, X + 1, X + 1, val);
    }
    i64 query(int L, int R){
        if(L <= R)
            return query(1, 1, n, L + 1, R + 1);
        else
            return -1ll;
    }
};

void solve() {
	int n, m, k, d;
	cin >> n >> m >> k >> d;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> a[i][j], a[i][j] ++;

	vector<i64> res(n);
	for(int i = 0; i < n; i ++){
		SegmentTree st(m, a[i]);
		for(int j = 1; j < m; j ++){
			int l = max(0, j - d - 1), r = j - 1;
			st.modify(j, st.query(l, r));
		}
		res[i] = st.query(m - 1, m - 1);
	}
	i64 sum = 0;
	for(int i = 0; i < k; i ++){
		sum += res[i];
	}
	i64 ans = sum;
	for(int i = k; i < n; i ++){
		sum += (res[i] - res[i - k]);
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}