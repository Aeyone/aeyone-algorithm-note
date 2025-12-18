#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
const int N = 2e5 + 10, mod = 998244353;
int st[N][20];
int a[N], b[N], _log2[N], n;
 
void init(int n) {
	memset(st, 0, sizeof st);
	_log2[0] = -1;
	for (int i = 1; i <= n; i ++)
		_log2[i] = _log2[i >> 1] + 1;
 
	for (int i = 1; i <= n; i ++)
		st[i][0] = a[i];

	for (int p = 1; (1 << p) <= n; p ++)
		for (int i = 1; i + (1 << p) - 1 <= n; i ++)
				st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		
}	
 
int query(int l, int r) {
	int d = _log2[r - l + 1];
	return max(st[l][d], st[r - (1 << d) + 1][d]);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> u(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i], u[a[i]] = i;
	init(n);
	vector<int> d;
	d.push_back(1);
	for(int i = 1; i <= m; i ++)
		cin >> b[i], d.push_back(u[b[i]]);
	d.push_back(n);
	for(int i = 0; i < d.size() - 1; i ++){
		int l = d[i], r = d[i + 1];
		int mx = max(a[l], a[r]);
		if(i == 0)
			mx = a[r];
		if(i == d.size() - 2)
			mx = a[l];
		if(query(l, r) > mx){
			cout << 0 << '\n';
			return;
		}
	}
	int cnt = 0;
	i64 ans = 1;
	for(int i = 1; i < d.size() - 2; i ++){
		int l = d[i], r = d[i + 1];
		for(int j = l; j < r; j ++){
			if(query(l, j) <= a[l] && query(j + 1, r) <= a[r])
				cnt ++;
		}
		ans = ans * cnt % mod;
		cnt = 0;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}