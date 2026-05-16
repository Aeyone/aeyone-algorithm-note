#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

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

const int N = 1e6 + 1;

void solve() {
	int n;
	cin >> n;
	
	int m = n * n + 40 * n;
	sieve(m);

	vector<vector<int>> a(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {

		}
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}