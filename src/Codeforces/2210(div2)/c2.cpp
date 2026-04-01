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
int m;

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
	vector<vector<int>> dp(n, vector<int>(21));
	for (int i = 1; i <= n; i ++) {
		int la = __gcd(a[i], a[i - 1]);
		int ne = __gcd(a[i], a[i + 1]);
		int l = lcm(la, ne);
		int L = a[i - 1] / la, R = a[i + 1] / ne;
		
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	sieve(50);
	p.push_back(1);
	m = p.size();
	while (_ --) {
		solve();
	}
}