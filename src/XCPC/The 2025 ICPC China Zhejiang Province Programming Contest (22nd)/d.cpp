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
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i ++) {
        cin >> a[i];
    }
    string s;
    int cur = 0;
    while (1) {
        if (cur - 1 >= 0 && a[cur - 1] > 1) {
            a[-- cur] --;
            s += "L";
        }else if (cur + 1 <= n && a[cur + 1] > 1) {
            a[++ cur] --;
            s += "R";
        } else {
            break;
        }
    }
    if (cur != n - 1 || ranges::count(a, 1) != a.size()) {
        cout << "Impossible" << '\n';
        return;
    }
    s += "R";
    s = s + string(n, 'L');
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}