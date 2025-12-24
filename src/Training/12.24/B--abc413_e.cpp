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
	vector<int> a(1 << n);
	for(int i = 0; i < 1 << n; i ++) {
		cin >> a[i];
	}
	for(int len = 1; len < 1 << n; len <<= 1) {
		for(int i = 0; i < 1 << n; i += (len << 1)) {
			if(i + (len << 1) <= (1 << n) && a[i] > a[i + len]) {
				for(int j = i; j < i + len; j ++) {
					swap(a[j], a[j + len]);
				}
			}
		}
	}
	for(auto e : a) {
		cout << e << ' ';
	}
	cout << '\n';
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