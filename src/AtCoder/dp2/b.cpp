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

void solve() {
	int A, B;
	cin >> A >> B;
	vector<int> a(A), b(B);
	int sum = 0;
	for (int i = 0; i < A; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < B; i ++) {
		cin >> b[i];
		sum += b[i];
	}
	vector dp(A + 1, vector<int>(B + 1, -INFLL));
	dp[A][B] = 0;
	for (int i = A; i >= 0; i --) {
		for (int j = B; j >= 0; j --) {
			if (i == A && j == B) {
				continue;
			} 
			dp[i][j] = max(i == A ? -INFLL : a[i] - dp[i + 1][j], j == B ? -INFLL : b[j] - dp[i][j + 1]);
		}
	}
	cout << (sum + dp[0][0]) / 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}