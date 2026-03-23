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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool check = false;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i > 0) {
			check |= (a[i] < a[i - 1]);
		}
	}
	if (!check) {
		cout << "Bob" << '\n';
		return;
	}

	bool ok = false;
	for (int i = 0; i < n; i ++) {
		int x = a[i], cnt = 0;
		while (x > 1) {
			int p = minp[x];
			cnt ++;
			while (x % p == 0) {
				x /= p;
			}
		}
		ok |= (cnt >= 2);
		a[i] = minp[a[i]];
	}

	if (ok) {
		cout << "Alice" << '\n';
	} else {
		bool ok = false;
		for (int i = 1; i < n; i ++) {
			ok |= (a[i] < a[i - 1]);
		}
		if (ok) {
			cout << "Alice" << '\n';
		} else {
			cout << "Bob" << '\n';
		}
	}
 
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	sieve(1e6);
	while (_ --) {
		solve();
	}
}