#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

string to_string(i64 num, int base){
	if(num == 0){
		return "0";
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

void solve () {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int len = n / 4;
    int ans = 0;

    for (int _i = 0;_i < (1 << (len - 1));_i++) {
        vector<int> cnt (n + 1);
        int i = _i | (1 << (len - 1));
        bool ok = true;
        for (int j = 0;j < n;j++) {
            cnt[a[j]]++;
            if (j % 4 == 3) {
                int idx = j / 4;
                if (i >> idx & 1) {
                    for (int k = 1;k <= n;k++) {
                        ok &= (cnt[k] == 4 || cnt[k] == 0);
                        cnt[k] = 0;
                    }
                }
            }
        }
        if (ok) {
            cerr << to_string(i, 2) << '\t';
        }
        ans += ok;
    }
    cout << ans << "\n";


}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}