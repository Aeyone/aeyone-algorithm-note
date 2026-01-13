/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 1e9 + 7;
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

int C(int N, int M) {//求n取m的组合数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

void solve() {//组合计数
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	if(m == 1){
		cout << n << '\n';
		return;
	}
	sort(a.begin(), a.end());
	i64 ans = 0;
	for(int l = 0, r = 0; l < n; l ++){
		while(r < n && (r - l + 1 < m || a[r] - a[l] <= k)){
			r ++;
		}
		if(r - l >= m){
			ans = (ans + C(r - l - 1, m - 1)) % MOD;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	init(200000);
	cin >> _;
	while (_ --){
		solve();
	}
}