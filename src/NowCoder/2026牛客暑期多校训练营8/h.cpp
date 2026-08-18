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

void solve()
{
    int n, x, sum = 0;
    i128 cnt = 1;
    cin >> n >> x;
    vector<int> a(n + 1);
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
        cnt += a[i] / x;
        a[i] %= x;
        if (a[i]) pq.push(a[i]);
    }
    if (x == 1) {
        cout << sum << endl;
        return;
    }
    while (pq.size()) {
        int sum = pq.top();
        if (sum + cnt >= x) {
            cnt -= x - sum - 1;
            pq.pop();
        } else {
            break;
        }
    }
    int ans = 0;
    if (pq.size()) {
        ans = (cnt - 1) % MOD;
        while (pq.size()) {
            ans = (ans + pq.top()) % MOD;
            pq.pop();
        }
    } else {
        while (cnt >= x) {
            cnt = cnt / x + cnt % x;
        }
        ans = (cnt - 1) % MOD;
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}