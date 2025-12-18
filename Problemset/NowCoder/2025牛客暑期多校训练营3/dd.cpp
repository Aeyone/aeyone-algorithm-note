#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dz[2] = {1, -1};

ll lowbit(ll n) {
    return n & -n;
}
int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}
int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (ll)a * res % p;
        b >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

void solve() {
    int n, a, ans = 0, cnt0 = 0, cnt1 = 0;
    string s;
    cin >> n >> a >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (cnt1 >= a) {
                ans++;
            } else
                cnt0++;
        } else {
            if (i == 0 || s[i - 1] == '0')
                cnt1 = 0;
            ans++;
            cnt1++;
            if (cnt1 >= a) {
                ans += cnt0;
                cnt0 = 0;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}