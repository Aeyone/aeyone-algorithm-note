#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), idx(n + 1), prei(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		idx[a[i]] = i;
		pre[i] = max(pre[i - 1], a[i]);
	}
	for(int i = 1; i <= n; i ++){
		prei[i] = max(prei[i - 1], idx[i]);
	}
	vector<vector<int>> st(n, vector<int>(20));
    for(int i = 0; i < n; i ++){
        st[i][0] = a[i + 1];
    }
    for(int p = 1; n >> p > 0; p ++){
        for(int i = 0; i + (1 << p) <= n; i ++){
            st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
        }
    }
    auto query = [&](int l, int r)->int{
    	l --, r --;
        int p = log2(r - l + 1);
        return max(st[l][p], st[r - (1 << p) + 1][p]);
    };
    vector<int> res(n + 1);
	for(int l = 1, r = 1; l <= n; l = r){
		int mx = query(l, r);
		while(prei[mx - 1] > r){
			r = prei[mx - 1];
			mx = query(l, r);
		}
		for(int i = l; i <= r; i ++){
			res[i] = mx;
		}
		r ++;
	}
	for(int i = 1; i <= n; i ++){
		cout << res[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}