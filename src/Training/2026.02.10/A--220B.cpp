#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int unit = 990; //块大小
int getBlock(int x){
	return x / unit;
}
struct Query {
  	int l, r, id;
  	bool operator<(const Query &x) const {//奇偶排序
	  	int a = getBlock(l), b = getBlock(x.l);
	    if (a != b){
	    	return l < x.l;
	    }
	    if(a & 1){
	    	return r < x.r;
	    }else{
		    return r > x.r;
	    }
  	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<Query> q(m);
	for (int i = 0; i < m; i ++) {
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	sort(q.begin(), q.end());

	vector<int> ans(m), cnt(n + 1);
	int l = 1, r = 0, res = 0;

	auto add = [&](int u)->void{
		if (a[u] <= n) {
			res -= cnt[a[u]] == a[u];
			cnt[a[u]] ++;
			res += cnt[a[u]] == a[u];
		} 
	};

	auto del = [&](int u)->void{
		if (a[u] <= n) {
			res -= cnt[a[u]] == a[u];
			cnt[a[u]] --;
			res += cnt[a[u]] == a[u];
		}
	};

	for (register int i = 0; i < m; i ++) {
		auto &[L, R, id] = q[i];
		while (l > L) add(-- l);
		while (r < R) add(++ r);
		while (l < L) del(l ++);
		while (r > R) del(r --);
		ans[id] = res;
	}
	for (auto e : ans) {
		cout << e << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}