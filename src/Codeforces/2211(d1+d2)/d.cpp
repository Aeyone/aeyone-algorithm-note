#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

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
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    //求某个阶乘的逆元
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int C(int N, int M) {//求n取m的组合数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int A(int N, int M) {//求n取m的排列数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[N - M] % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> cnt(30); // 记录每位最终出现的次数
	for (int i = n; i >= 1; i --) {
		int x = a[i];
		for (int j = 0; j < 30; j ++) { // 去掉这位产生的次数比当前i更大的位的贡献
			x = (x + MOD - C(cnt[j], i) * (1ll << j) % MOD) % MOD; 
		}
		for (int j = 0; j < 30; j ++) {
			if (x >> j & 1) {
				cnt[j] = i; // 当前x保证一定是所有次数为i次的位，而组成的数字
			}
		}

	}
	vector<int> b(n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 30; j ++) {
			if (cnt[j]) {
				b[i] |= (1 << j);
				cnt[j] --;
			}
		}
	}
	for (auto e : b) {
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init(2e5);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}