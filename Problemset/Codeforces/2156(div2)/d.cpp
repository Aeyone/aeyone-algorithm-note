#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

int query(int i, int x){
	cout << "? " << i << ' ' << x << endl;
	int q;
	cin >> q;
	return q;
}

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> bit(30);
	for(int i = 1; i <= n; i ++){
		for(int j = 0; i >> j > 0; j ++){
			bit[j][(i >> j & 1)] ++;
		}
	}
	vector<int> que(n, 1);
	int p = 0;
	int ans = 0;
	map<int, bool> mp;
	while(n >> p > 0){
		int cnt = 0;
		vector<int> vis(n);
		for(int i = 1; i <= n - 1; i ++){
			if(!que[i]){
				continue;
			}
			int x = query(i, 1 << p);
			cnt += x;
			vis[i] = x;
		}
		int sign = (cnt != bit[p][1]);//该位上数目不对
		ans += sign * (1 << p);
		for(int i = 1; i <= n; i ++){
			if((i >> p & 1) == sign || vis[i]){
				continue;
			}
			vis[i] = true;
			for(int j = 0; i >> j > 0; j ++){//把多余的去除，即缩小范围
				bit[j][(i >> j & 1)] --;
			}
		}
		for(int i = 1; i <= n - 1; i ++){
			que[i] &= (vis[i] == sign);
		}
		p ++;
	}
	cout << "! " << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}