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
	string s;
	cin >> s;
	int sum = 0;
	priority_queue<int> pq;
	for (int i = 0; i < s.size(); i ++) {
		sum += (s[i] - '0');
		if (i) {
			pq.push(s[i] - '0');
		} else {
			pq.push(s[i] - '0' - 1);
		}
	}
	int ans = 0;
	while (pq.size() && sum >= 10) {
		sum -= pq.top();
		pq.pop();
		ans ++;
	}
	cout << ans << '\n';

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