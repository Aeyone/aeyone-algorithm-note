#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

struct Info{
    i64 sum = 0, cnt = 0;
};

Info operator+(const Info &l, const Info &r){
   return Info(l.sum + r.sum, l.cnt + r.cnt);
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
    }

    void up(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void modify(int p, int l, int r, int L, int R, i64 val, int sign){
        if (L > r || R < l){
            return;
        }
        if (L <= l && r <= R){ 
            if(sign == 1){
                info[p].sum += val;
                info[p].cnt ++;
            }else{
                info[p].sum -= val;
                info[p].cnt --;
            }
        }else{
            int mid = (l + r) / 2;
            modify(2 * p, l, mid, L, R, val, sign);
            modify(2 * p + 1, mid + 1, r, L, R, val, sign);
            up(p);
        }
    }

    Info query(int p, int l, int r, int L, int R){
        if(L > r || R < l){
            return Info(0, 0);
        }
        Info res = {0, 0};
        if(L <= l && r <= R){
            res = info[p];
        }else{
            int mid = (l + r) / 2;
            res = res + query(2 * p, l, mid, L, R);
            res = res + query(2 * p + 1, mid + 1, r, L, R);
        }
        return res;
    }
    //1-based
    void modify(int x, i64 val, int sign){
        modify(1, 1, n, x, x, val, sign);
    }

    Info query(int L, int R){
        return query(1, 1, n, L, R);
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<array<int, 2>> a(n + 1), alls;
    int mx = 0;
    map<int, int> mp;
	for(int i = 1; i <= n; i ++){
		cin >> a[i][0];
        a[i][1] = mp[a[i][0]] ++;
        mx += (a[i][0] > 0);
	}
    alls = a;

    vector<array<int, 3>> que(q);
	for(auto &[u, e, c] : que){
        cin >> u >> e;
        c = mp[e] ++;
		alls.push_back({e, c});
	}
	sort(alls.begin(), alls.end());

	int m = alls.size();
    map<array<int, 2>, int> idx;
    for(int i = 0; i < m; i ++){
        idx[alls[i]] = i + 1;
    }

    SegmentTree st(m);
    for(int i = 1; i <= n; i ++){
        st.modify(idx[a[i]], a[i][0], 1);
    }

    for(auto [u, e, c] : que){
        mx -= (a[u][0] > 0), mx += (e > 0);
        st.modify(idx[a[u]], a[u][0], 0);
        a[u] = {e, c};
        st.modify(idx[a[u]], a[u][0], 1);
        
        int l = 1, r = m, mn = n;
        while(l <= r){
            int mid = (l + r) / 2;
            Info tmp = st.query(1, mid);
            if(tmp.sum <= 0){
                mn = (n - tmp.cnt), l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        cout << mx - mn + 1 << '\n';
    }
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}