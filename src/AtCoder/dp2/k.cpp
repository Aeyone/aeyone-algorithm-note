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
    i64 max = 0;
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
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n;
	cin >> n;
	using T = array<int, 2>;
	vector<T> a(n);
	vector<int> tot;
	for (auto &[x, r] : a) {
		cin >> x >> r;
		tot.push_back(x - r);
		tot.push_back(x + r);
	}
	sort(a.begin(), a.end(), [](const T &a, const T &b)->bool {
		int la = a[0] - a[1], ra = a[0] + a[1];
		int lb = b[0] - b[1], rb = b[0] + b[1];
		return (ra < rb || (ra == rb && la < lb)); // 按照右端点升序排序，右端点相同左端点升序，消除影响
	});

	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());

	auto find = [&](int x)->int {
		int idx = lower_bound(tot.begin(), tot.end(), x) - tot.begin();
		return (tot[idx] == x ? idx + 1 : -1);
	};

	int m = tot.size();
	SegmentTree st(m);

	for (auto [x, r] : a) {
		int lo = find(x - r), hi = find(x + r);
		st.modify(lo, st.query(lo + 1, hi).max + 1);
	}

	cout << st.query(1, m).max << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}