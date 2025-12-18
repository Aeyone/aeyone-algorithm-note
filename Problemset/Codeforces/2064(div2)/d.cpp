#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i], pre[i] = a[i] ^ pre[i - 1];

	vector<array<int, 31>> f(n + 1);
	for(int i = 1; i <= n; i ++){
		for(int j = 30; j >= 0; j --){
			if((a[i] >> j) & 1)
				f[i][j] = i;
			else
				f[i][j] = f[i - 1][j];
		}
	}
	while(q --){
		int x;
		cin >> x;
		int now = n, tar = 1, mx = 1;
		for(int i = 30; i >= 0; i --){
			if(!((x >> i) & 1)){//当前位是0 最多走到当前位是1的史莱姆的前一个
				mx = max(mx, f[now][i] + 1);
				continue;
			}
			if(f[now][i] >= mx)
				tar = f[now][i];
			else{
				tar = mx - 1;
				break;
			}
			x ^= (pre[now] ^ pre[tar]);
			if(x < a[tar])
				break;
			else
				x ^= a[tar --];

			now = tar;
			mx = max(mx, f[now][i] + 1);
		}
		cout << n - tar << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}