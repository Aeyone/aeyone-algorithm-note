#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<vector<int>> buk(30);

string to_string(i64 num, int base, int siz){
	if(num == 0){
		return string(siz, '0');
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	while (res.size() < siz) {
		res += "0";
	}
	reverse(res.begin(), res.end());
	return res;
}

void init() {
	for (int i = 0; i < 1 << 20; i ++) {
		buk[__builtin_popcount(i)].push_back(i);
	}
	for (int i = 0; i <= 20; i ++) {
		ranges::sort(buk[i]);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int c1 = ranges::count(s, '1');
	int ans = -1;
	for (int i = 0; i <= k; i ++) {
		if (__lg(c1 + i) >= k) {
			break;
		}
		int idx = ranges::lower_bound(buk[i], c1 + i) - buk[i].begin();
		if (idx < buk[i].size() && buk[i][idx] == c1 + i) {
			ans = c1 + i;
			break;
		}
	}
	if (ans == -1) {
		cout << "None" << '\n';
	} else {
		cout << to_string(ans, 2, k) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init();
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}