#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 1e5 + 10;
int p[N], cnt;

void init(int n){
	vector<bool> vis(n + 1);
	for(int i = 2; i <= n; i ++){
		if(!vis[i])
			p[cnt ++] = i;
		for(int j = 0; p[j] <= n / i; j ++){
			vis[p[j] * i] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}

int divide(int x){
	int res = 0;
	for(int i = 0; i < cnt; i ++)
		while(x % p[i] == 0)
			x /= p[i], res ++;
	if(x > 1)
		res ++;
	return res;
}

void solve() {
	int a, b, k;
	cin >> a >> b >> k;

	int mn = 0, mx = divide(a) + divide(b);
	if(a != b && max(a, b) % min(a, b) == 0)
		mn = 1;
	else
		mn = 2;

	if(k >= mn && k <= mx)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	init(1e5);
	cin >> _;
	while (_ --)
		solve();
}