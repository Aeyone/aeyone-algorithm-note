#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//迷你版线段树
	int n, m;
	cin >> n >> m;
	vector<int> a(1 << n + 1);
	for(int i = 1; i <= 1 << n; i ++){
		cin >> a[i];
	}
	vector<int> res(4 << n);
	auto modify = [&](auto &&self, int l, int r, int p, int cnt, int x, int v)->void{
		if(x < l || x > r){
			return;
		}
		if(l == r){
			res[p] = v;
		}else{
			int mid = (l + r) / 2;
			self(self, l, mid, 2 * p, !cnt, x, v);
			self(self, mid + 1, r, 2 * p + 1, !cnt, x, v);
			if(cnt){
				res[p] = (res[2 * p] | res[2 * p + 1]);
			}else{
				res[p] = (res[2 * p] ^ res[2 * p + 1]);
			}
		}
	};
	for(int i = 1; i <= 1 << n; i ++){
		modify(modify, 1, 1 << n, 1, (n & 1), i, a[i]);
	}
	while(m --){
		int x, v;
		cin >> x >> v;
		modify(modify, 1, 1 << n, 1, (n & 1), x, v);
		cout << res[1] << '\n';
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