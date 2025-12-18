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

bool Miller_Rabin(i64 n) { //米勒罗宾判断素数
    i64 cnt = 0, m = n - 1;
    if(n == 2 || n == 3) {
        return true;
    }
    if(n == 1 || (n % 6 != 1 && n % 6 != 5)) {
        return false;
    }
    while(m % 2 == 0) {
    	m /= 2, cnt ++;
    }
    for(int i = 1; i <= 10; i ++) {
        i64 x = 1ll * rand() * rand() % (n - 1) + 1, res = qmi(x, m, n), lres = res;
        if(res == 1){
            continue;
        }
        for(int i = 1; i <= cnt; i ++) {
            res = (i128)res * res % n;
            if(res == 1 && lres != n - 1) {
            	return false;
            }
            if(res == 1) {
                break;
            }
            lres = res;
        }
        if(res != 1){
            return false;
        }
    }
    return true;
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
		ans += Miller_Rabin(i);
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