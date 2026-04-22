#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 20100403;

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p){
    i64 res = 1;
    for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
         res = a * res % p;
    }
    return res;
}

void init(int n) {
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int C(int N, int M) {
    if (M > N || M < 0) {
        return 0;
    }
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}
/*
*	把1视为+1，0视为-1
*	记第一个前缀为-1的地方为x，翻转1~x所有01数字
*	则其中1的数量：n -> n + 1，0的数量 m -> m - 1
*	将非法序列S翻转1~x后的序列记为S'
*	S->S':
*		因为所有不合法的一定存在一个前缀和为-1，所以所有S都对应有一个S'
*	S'->S:
*		因为所有S'的总和一定是+2，所以一定存在一个前缀和为+1的位置，
*		将这个前缀全部翻转前缀和一定为-1，最后的总和一定为0，所有S'都对应一个S
*/
void solve() {
	int n, m;
	cin >> n >> m;
	cout << (C(n + m, n) - C(n + m, n + 1) + MOD) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init(2e6);
	int _ = 1;
	while (_ --) {
		solve();
	}
}