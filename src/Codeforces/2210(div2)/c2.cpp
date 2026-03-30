#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

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
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2), b(n + 2);
	a[0] = a[n + 1] = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int la = __gcd(a[i], a[i - 1]);
		int ne = __gcd(a[i], a[i + 1]);
		int mul = (a[i - 1] / la) * (a[i + 1] / ne);
		int l = lcm(la, ne);
		int prim = 0;
		if (a[i] != l) {
			prim = 1;
		} else {
			for (auto e : p) {
				if (mul % e != 0) {
					prim = e;
					break;
				}
			}
		}
		cerr << "prim = " << prim << " lcm = " << l << '\n';
		ans += (prim * l <= b[i]);

	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	sieve(1e5);
	while (_ --) {
		solve();
	}
}