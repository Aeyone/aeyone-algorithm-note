#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p){
		if(b & 1)
			res = a * res % p;
	}
	return res;
}
void init(int n) {
    //求阶乘
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;

    //求某个阶乘的逆元
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	sort(a.begin(), a.end());
	i64 ans = 1;
	vector<int> b;
    for(int i = 0; i < n; i ++){
        b.push_back(a[i]);
        int x = b.size() - (lower_bound(b.begin(), b.end(), a[i] - d) - b.begin());
        cerr << "x = " << x << '\n';
        ans = ans * x % MOD;
    }
    for(auto [e, c] : mp){
		ans = ans * inv[c] % MOD;
    }
    cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init(1000000);
	// cin >> _;
	while (_ --){
		solve();
	}
}