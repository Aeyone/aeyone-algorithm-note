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
	string a, b;
	cin >> a >> b;

	vector<int> A, B;

	auto run = [&](string& s, vector<int>& A)-> void {
		int n = s.size();
		for (int l = 0, r = 0; l < n; l = r) {
			if (s[l] == '.') {
				r ++;
				continue;
			}
			while (r < n && s[r] != '.') {
				r ++;
			}
			int len = r - l;
			A.push_back(stoi(s.substr(l, len)));
		}
	};
	run(a, A);
	run(b, B);
	if (A > B) {
		cout << "A" << '\n';
	} else if (B > A) {
		cout << "B" << '\n';
	} else {
		cout << "Equal" << '\n';
	}
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