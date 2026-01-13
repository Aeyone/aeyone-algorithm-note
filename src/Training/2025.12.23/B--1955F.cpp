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
	int p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	cout << (p2 / 2) + (p3 / 2) + (p4 / 2) + ((p1 & 1) && (p1 & 1) == (p2 & 1) && (p2 & 1) == (p3 & 1)) + (p1 / 2) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}