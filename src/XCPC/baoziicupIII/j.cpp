#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int query (int u, int v) {
    cout << "? " << u << " " << v << endl;
    int x;cin >> x;
    return x;
}

void solve () {
    int n;
    cin >> n;
    int cur = 1;
    for (int i = 2; i <= n; i ++) {
    	if (!query(i, cur)) {
    		cur = i;
    	}
    }

    int ok = true;
    for (int i = 1; i <= n; i ++) {
    	if (i != cur) {
	    	ok &= query(i, cur);
	    	ok &= !query(cur, i);
	    }
    }
    if(ok) {
    	cout << "! " << cur << endl;
    } else {
    	cout << "! -1" << endl;
    }
}

signed main() {
	// ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}