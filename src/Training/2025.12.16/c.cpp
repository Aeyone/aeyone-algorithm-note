#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
const int N = 1e7;
int p[N + 1], vis[N + 1], psiz;

void build() {
	for(int i = 2; i <= N; i ++) {
		if(!vis[i]){
			p[psiz ++] = i;
		}
		for(int j = 0; j < psiz && p[j] <= N / i; j ++) {
			vis[p[j] * i] = true;
			if(i % p[j] == 0){
				break;
			}
		}
	}
}
i64 qmi(i64 a, i64 b, i64 p) {
	i64 res = 1;
	for( ;b ; b >>= 1, a = (i128)a * a % p) if(b & 1) {
		res = (i128)a * res % p;
	}
	return res;
}

// 米勒-拉宾素性测试
bool isprime(i64 n) {
    if(n == 2 || n == 3){
        return true;
    }
    if(n <= 1 || n % 6 != 1 && n % 6 != 5){
        return false;
    }
    static constexpr int A[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };  // 预定义的基数
    int s = __builtin_ctzll(n - 1);                                 // 计算 n-1 的尾零个数
    i64 d = (n - 1) >> s;                                           // d = (n-1) / 2^s
    for(auto a : A) {
        if(a == n){
            return true;                // 如果 a 是 n，直接返回 true
        }
        i64 x = qmi(a, d, n);           // 计算 a^d % n
        if(x == 1 || x == n - 1){
            continue;                   // 继续测试其他基数
        }
        bool ok = false;
        for(int i = 0; i < s - 1; i ++) {
            x = (i128)x * x % n;        // x = x^2 % n
            if (x == n - 1) {
                ok = true;              // 找到 n-1，证明 n 是素数
                break;
            }
        }
        if(!ok){
            return false;               // 如果没有找到，n 不是素数
        }
    }
    return true;                        // 所有基数都通过，n 是素数
}

void solve() {
	i64 L, R;
	cin >> L >> R;
	int ans = 1;
	for(int i = 0; i < psiz && 1ll * p[i] * p[i] <= R; i ++) {
		i128 cur = 1ll * p[i] * p[i];
		while(cur <= R) {
			ans += (cur > L);
			cur *= p[i];
		}
	}
	for(i64 i = L + 1; i <= R; i ++) {
		ans += isprime(i);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	build();
	// cin >> _;
	while (_ --) {
		solve();
	}
}