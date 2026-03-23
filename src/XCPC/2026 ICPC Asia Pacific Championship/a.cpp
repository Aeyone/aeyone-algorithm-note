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
	vector<int> a = {1};

	auto query = [&](int i, int j)-> string {
		string res;
		cout << "query " << i << ' ' << j << endl;
		cin >> res;
		return res;
	};

	for (int i = 2; i <= n; i ++) {
		int l = 0, r = i - 2, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(a[mid], i) == "first") {
				ans = mid, l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		a.push_back(i);
		for (int j = a.size() - 1; j - 1 > ans; j --) {
			swap(a[j], a[j - 1]);
		}
	}
	cout << "answer ";
	for (auto e : a) {
		cout << e << ' ';
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}