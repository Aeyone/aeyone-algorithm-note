#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<array<int, 2>> back;
vector<vector<int>> tot(1e6 + 10);

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void init() {
	auto check = [&](int x)-> int {
		if (x < 10) {
			return x;
		}
		string s = to_string(x);
		int n = s.size();
		ranges::reverse(s);
		int sum = s[0] - '0';
		if (sum == 0) {
			return 0;
		}
		for (int l = 1, r = 1; l < n; l = r) {
			int cur = 0, curSum = 0;
			while (r < n && cur < sum) {
				cur += (s[r] - '0');
				curSum += qmi(10, r - l) * (s[r] - '0');
				r ++;
			}
			if (cur == sum) {
				sum = curSum;
			} else {
				return 0;
			}
		}
		return sum;
	};
	for (int i = 1; i <= 1e6; i ++) {
		int num = check(i);
		if (num > 0) {
			back.push_back({num, i});
		}
	}
	ranges::sort(back);
	for (int i = 1; i <= 1e6; i ++) {
		string s = to_string(i);
		int sum = 0;
		for (auto e : s) {
			sum += (e - '0');
		}
		int lo = lower_bound(back.begin(), back.end(), array<int, 2>{sum, 0}) - back.begin();
		int hi = upper_bound(back.begin(), back.end(), array<int, 2>{sum, INF}) - back.begin();
		for (int j = lo; j < hi; j ++) {
			tot[i].push_back(back[j][1]);
		}
	}

}

void solve() {
	string s;
	cin >> s;
	if (s.size() < 2) {
		cout << s << '\n';
		return;
	}
	vector<int> cnt(10);
	for (auto e : s) {
		cnt[e - '0'] ++;
	}
	for (int i = s.size() * 50; i >= 1; i --) {
		vector<int> cur = cnt;
		string s = to_string(i);
		int mn = INF;
		for (auto e : s) {
			cur[e - '0'] --;
			mn = min(mn, cur[e - '0']);
		}
		if (mn < 0) {
			continue;
		}
		for (auto e : tot[i]) {
			string s1 = to_string(e);
			for (auto e : s1) {
				cur[e - '0'] --;
				mn = min(mn, cur[e - '0']);
			}
			if (mn < 0) {
				continue;
			}
			int r = 0;
			string ans;
			for (int j = 9; j >= 0; j --) {
				r += j * cur[j];
				ans += string(cur[j], char('0' + j));
			}
			if (r == i) {
				cout << ans + s + s1 << '\n';
				return;
			} else if (r == 0) {
				string res = string(1, s[0]) + string(cur[0], '0') + s.substr(1, s.size() - 1) + s1;
				cout << res << '\n';
				return;
			}
		}
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init();
	cin >> _;
	while (_ --) {
		solve();
	}
}