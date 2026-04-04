#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 5e6 + 10;

int ans[N];

i64 qmi(i64 a, i64 b, i64 p) {
	i64 res = 1;
	for( ;b ; b >>= 1, a = (i128)a * a % p) if(b & 1) {
		res = (i128)a * res % p;
	}
	return res;
}

vector<int> minp, p;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            p.push_back(i);
        }
        for (auto e : p) {
            if (1ll * i * e > n) {
                break;
            }
            minp[i * e] = e;
            if (e == minp[i]) {
                break;
            }
        }
    }
	for (int i = 1; i < N; i ++) {
		ans[i] = (minp[3 * i + 7] == 3 * i + 7) + ans[i - 1];
	}
}

void solve() {
	int n;
	cin >> n;
	cout << ans[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	sieve(2e7);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}