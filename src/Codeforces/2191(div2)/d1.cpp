#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
    string s;
    cin >> n >> s;
    n = s.size();
    vector<array<int, 2>> c(n + 1);
    vector<int> to(n);
    int cnt = 0, ans = -1, cur = n;
    for (int i = n - 1; i >= 0; i --) {
        c[i][0] = c[i + 1][0] + (s[i] == '(');
        c[i][1] = c[i + 1][1] + (s[i] == ')');
        to[i] = cur;
        cur = (s[i] == '(' ? i : cur);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (c[to[i]][0] && cnt + 1 <= c[to[i]][1]) {
                ans = max(ans, n - 2 * (to[i] - i));
            }
            cnt --;
        } else {
            cnt ++;
        }
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